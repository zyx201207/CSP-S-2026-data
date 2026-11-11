#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5*1e5+10;
ll n,m,a[N],am[N],b[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll n1=0,ck=0;
	for(int i=1;i<=n;i++)
	{
		n1=0;
		memset(am,0,sizeof(am));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
			am[++n1]=a[j];
		ll f=0;
		for(int j=1;j<=n1;j++)
		{
			if(b[am[j]]==0)
				b[am[j]]=j;
			else
			{
				for(int k=b[am[j]];k<j;k++)
					am[k]=0,b[am[k]]=0;
				b[am[j]]=j;
			}
		}
		for(int j=1;j<=n1;j++)
			ans[am[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
