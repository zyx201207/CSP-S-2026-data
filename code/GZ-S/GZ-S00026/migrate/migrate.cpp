//GZ-S00026 张蔚远 贵阳白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005],ans=0;
vector< vector <int> > a(2000005);
long long bfs(int xx,int y){
	long long dis[200005];
	bool vis[200005];
	for(int i=1;i<=n;i++){
		dis[i]=LONG_LONG_MAX;
		vis[i]=false;
	}
	dis[xx]=0;
	queue <int> q;
	q.push(xx); 
	while(!q.empty()){
		int c=q.front();
		q.pop();
		if(c==y){ 
			int d=q.front(); 
		  	if(d==y){
				ans++;		
			}
			break;
		}
		for(int i : a[c]){
			if(vis[i]==false){
				vis[i]=true; 	
				dis[i]=min(dis[i],dis[c]+1);
				q.push(i);
		}
		
		}
	}
	return dis[y];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					a[i].push_back(j);
					a[j].push_back(i);
				}
				else {
					break;
				}
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			bfs(i,j);
		}
	} 
	cout<<ans;
}
	return 0;
} 
