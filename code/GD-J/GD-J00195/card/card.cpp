#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,m;
ll a[N];
ll flag=0;
ll last[N];
ll ans[N];
ll vis[N];
ll op[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])flag=1;
	}
	if(flag==0)
	{
		//cout<<141514;
		ll po=0;
		ll pop=1;
		op[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]==a[i+1])break;
			else op[i]=i,pop++;
		}
		for(int i=1;i<=n;i++)
		{
			cout<<op[i]<<" ";
		}
		return 0;
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				last[j]=-1;
				vis[j]=0;
			}
			ll cut=0,dic=0;
			for(int j=i;j<=n;j++)
			{
				if(last[a[j]]!=-1&&vis[last[a[j]]]==0)
				{
					cut=j,dic=last[a[j]];
					//cout<<vis[last[j]]<<" ";
					//if(dic<=8&&cut>8)cout<<vis[dic]<<"????";
					for(int k=dic;k<cut;k++)
					{
						vis[k]=1;
					}
					//cout<<dic<<" "<<cut<<"\n";
					//if(j==4)cout<<cut<<"?";
				}
				/*for(int j=i;j<=n;j++)
				{
					cout<<vis[j]<<" ";
				}
				cout<<"\n";*/
				last[a[j]]=j;
			}
			//cout<<"here is dividing line...\n";
			//cout<<max(i*1ll,cut)<<" ";
			for(int j=i;j<=n;j++)
			{
				//cout<<vis[j]<<" ";
				if(vis[j]==0)ans[a[j]]++;
				
			}
			//cout<<"\n";
			//cout<<"\n";
			//cout<<cut<<" ";
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		//cout<<ans[1];
		return 0;
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)cout<<i<<" ";
		return 0;
	}
	//cout<<flag;
	for(int i=1;i<=n;i++)
	{
		cout<<"Rp++ ";
	}
	return 0;
}

