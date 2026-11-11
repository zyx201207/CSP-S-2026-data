#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],l,cnt;
char c[200005];
string s;
bool f=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]<=1000)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=c[i];
			}
		}
		else f=0;
		l+=a[i];
	}
//	cout<<s<<" "<<l;
	if(l<2*100000000)
	{
		for(int i=0;i<l/2;i++)
		{
			if(s[i]!=s[l-i-1])
			{
//				cout<<"!";
//				cout<<s[i]<<" "<<s[l-i-1]<<"\n";
				cnt++;
			}
		}
		cout<<cnt;
	}
	else
	{
		int ll=1,r=n;
		while(ll!=r)
		{
			if(c[ll]!=c[r])
			{
				cnt+=min(a[ll],a[r]);
			}
			int tt=min(a[ll],a[r]);
			a[ll]-=tt;
			a[r]-=tt;
			if(a[ll]==0)ll++;
			if(a[r]==0)r--;
		}
		cout<<cnt;
	}
	return 0;
}
