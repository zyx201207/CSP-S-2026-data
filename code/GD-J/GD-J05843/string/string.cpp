#include<bits/stdc++.h>
using namespace std;
long long n,k[200007],ans,m;
string s;
char c[200007];
bool f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i]>>c[i];
		m+=k[i];
		if(c[i]!=c[i-1]&&i!=1) f=1;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			s+=c[i];
		}
	}
	int l=1,q=0,r=n,w=m+1;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(k[l]<k[r])
			{
				q+=k[l];
				w-=k[l];
				l++;
			}
			else 
			{
				q+=k[r];
				w-=k[r];
				r--;
			}
		}
		else
		{
			if(k[l]<k[r])
			{
				ans+=k[l];
				q+=k[l];
				w-=k[l];
				l++;
			}
			else
			{
				ans+=k[r];
				q+=k[r];
				w-=k[r];
				r--;
			}
		}
	}
	/*for(int i=0;i<m/2;i++)
	{
		if(s[i]!=s[m-i-1]) ans++;
	}*/
	cout<<ans;
	return 0;
}
