#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ste[2000005],m,ans,de,sum;bool tpA=true;
void dfs(int nw,int ov,int nws,int nes,int sd)
{
	cout<<nw<<" "<<nws<<" "<<nes<<" "<<sd<<endl;
	if(nws==nes&&nw==ov){sum++;return ;}
	if(nws>nes)return ;
	if(a[nw+1]-a[nw]<=sd)dfs(nw+1,ov,nws,nes,sd-(a[nw+1]-a[nw]));
	dfs(nw,ov,nws+1,nes,d);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>=3)if(de!=a[i]-a[i-1])tpA=false;
			if(i>=2)de=a[i]-a[i-1];
		}
			for(int i=1;i<=n;i++)
			{
				for(int j=1+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d)continue;
					if((a[j]-a[i])%d!=0)
					{
						//cout<<i<<"to"<<j<<endl;
						ans++;
					}
				}
			}
		cout<<ans<<endl;
	 } 
	return 0;
 } 
