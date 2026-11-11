#include<bits/stdc++.h>
using namespace std;
int n,flag[2000010],dis[2000010],s[2000010];
long long d,x[2000010],ans;
vector <int> v[2000010];
struct node{
	int p,len;
};
void bfs(int t){
	queue<node> q;
	memset(flag,0,sizeof(flag));
	memset(dis,0x3f,sizeof(dis));
	memset(s,0,sizeof(s));
	q.push({t,0});
	dis[t]=0;
	flag[t]=1;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		for(int i=0;i<v[now.p].size();i++){
			int neww=v[now.p][i];
			if(dis[neww]>dis[now.p]+1){
				dis[neww]=dis[now.p]+1;
				s[neww]=1;
				q.push({neww,dis[neww]});
			}else if(dis[neww]==dis[now.p]+1){
				s[neww]++;
				q.push({neww,dis[neww]});
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		if(i==t)continue;
		if(s[i]==2)ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int jjb,T;
	cin>>jjb>>T;
	while(T--){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		v[i].clear();
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(x[i]-x[j])<=d){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	cout<<ans/2<<"\n";
	
	}
	return 0;
}
