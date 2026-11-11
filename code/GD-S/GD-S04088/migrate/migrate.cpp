#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],ans,dis[2000010],anss;
bool vis[2000010],b[2000010];
long long sum;
struct node{
	long long xb,step;
};
int main()
{
	queue<node> q;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=sum;
			if(a[i]<0){
				sum=0-a[i]+sum+1;
				a[i]+=sum;
			}
		}
		for(int i=1;i<=n;i++){
			vis[i]=false;
			b[i]=false;
		}
		ans=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++){
				dis[i]=0x3f3f3f;
			}
			q.push({a[k],0});
			while(!q.empty())
			{
				node u=q.front();
				q.pop();
				for(int i=u.xb;i<=n;i++)
				{
					if(a[i]-a[u.xb]>d)break;
					if(u.step+1>dis[i])continue;
					else if(u.step+1==dis[i]&&!vis[i]){
						vis[i]=true;
						ans++;
					}
					else if(u.step+1==dis[i]&&vis[i]&&!b[i]){
						ans--;
						b[i]=true;
					}
					q.push({a[i],u.step+1});
					dis[i]=u.step+1;
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
