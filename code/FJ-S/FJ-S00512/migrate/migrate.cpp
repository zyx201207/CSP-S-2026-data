#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,x[2000010],l[2000010],n,d;
int cnt[2000010],dis[2000010],ans=0;
bool vis[2000010];
vector<int>g[2000010];
int spfa(int s){
	for(int i=1;i<=n;i++)dis[i]=1e9;
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	queue<int>z;
	z.push(s);
	vis[s]=1;
	dis[s]=0;
	cnt[s]=1;
	while(z.size()){
		int x=z.front();
		z.pop();
		vis[x]=0;
		for(int i=0;i<g[x].size();i++){
			//cout<<x<<" "<<g[x][i]<<endl;
			int v=g[x][i];
			if(dis[x]+1<dis[v]){
				
				dis[v]=dis[x]+1;
				//cout<<v<<" "<<x<<endl;
				cnt[v]=cnt[x];
				if(!vis[v]){
					vis[v]=1;
					z.push(v);
				}

			}else if(dis[x]+1==dis[v])cnt[v]++;
		}
	}
	//for(int )
	for(int i=1;i<=n;i++){
		//cout<<cnt[i]<<" ";
		if(i!=s&&cnt[i]==2)ans++;
	}
	//cout<<endl;
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
scanf("%d%d",&c,&t);
while(t--){
	ans=0;
	bool flag=0,flag2=1;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	int L=1,R=2;
	for(int i=1;i<=n;i++){
		int j=i+1;
		while(x[j]<=x[i]+d&&j<=n){
			g[i].push_back(j);
		//	cout<<x[j]<<" "<<x[i]+d<<" "<<i<<" "<<j<<endl;
			j++;
		}
	}
	for(int i=1;i<=n;i++)spfa(i);
	printf("%d\n",ans);
}
return 0;
}
/*
wozadabaolidaleINFs/kk
*/
