#include<bits/stdc++.h>
using namespace std;
long long c,T;
long long x[2000001];
//int m[2000001];
long long n,d;
long long xx[10001],num[10001];
int dfs(int u,int step)
{
	if(step!=0){
		if(step==xx[u])num[u]++;
	if(step<xx[u])
	{
		num[u]=1;
		xx[u]=step;
	}
	}
	
	for(int i=u+1;i<=n;i++)
	{
		if(x[i]-x[u]<=d)dfs(i,step+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n<=10)
		{
			long long ans=0;
			for(int i=1;i<=n;i++){
				memset(xx,0x3f,sizeof(xx));
				dfs(i,0);
				for(int j=1;j<=n;j++)
				{
					if(num[j]==2)ans++;
					num[j]=0;
				}
			}
			cout<<ans<<'\n';
			continue;
			
		}
		
		
		//if(n>=2000000)
		//{
			long long  ca=x[2]-x[1];
			long long pp=d/ca;
			if(pp<=1)
			{
				cout<<"0"<<'\n';
			}
			else
			{
				cout<<max((long long)0,n-(pp*2-1))<<'\n';
			}
		//}
	}
	return 0;
}
