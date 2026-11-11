#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long d[N],a1,b1,ans=0,maxn,r,l;
char c[8];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d[i]>>c[i];
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	r=n+1;
	for(int i=0;i<n;i++)
	{
		if(c[r]==c[l]&&r<=n)
		{
			ans+=b1-a1;
		}
		a1+=d[i];
		if(r==i) break;
		while(b1<a1)
		{
			r--;
			b1+=d[r];
			if(b1<a1)
			{
				if(c[i]!=c[r])
				{
					ans+=d[r];
				}
			}
			else
			{
				if(c[i]!=c[r])
				{
					ans+=a1-(b1-d[r]);
				}
				break;
			}
			if(r==1) break;
		}
		if(r==1) break;
	}
	cout<<ans<<'\n';
	return 0;
}
