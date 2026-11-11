#include<bits/stdc++.h>
using namespace std;//dj最短路+分层图试一下 
const long long NM=(5e5+5)*(25),Q=1e5+5;
const int N=5e5+5;
struct ed{
	long long v,w;
};
struct qe{
	long long x,y,id;
}que[Q];
long long cnt[N];
vector<ed>e[NM]; long long c,n,m,d,q;
long long dis[NM]; 
long long ans[Q];
void ad(long long u, long long v, long long w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
bool cmp(qe a,qe b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
void dj(int st){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>
,greater<pair<long long,long long>>>q;//dis[u]第一关键字,u第二关键字 
	memset(dis,0x7f,sizeof(dis));//初始化
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		long long dist=q.top().first,u=q.top().second;
		q.pop();//出队 
		if(dist>dis[u])continue;
		for(auto po : e[u]){
			long long w=po.w,v=po.v;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});//感觉无误 
			}
		}
	}
	return ;
}
		int a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cnt[i]=1;
	}
	for(int i=1;i<=m;i++){
		int w;cin>>w;
		ad(i,i+m,w);
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			cnt[a[j]]++;
			ad(a[j]+m,a[j]+(m*cnt[a[j]]),t[j]);
			if(j>=2)ad(a[j-1]+(m*cnt[a[j-1]]),a[j]+(m*cnt[a[j]]),0);//建分层图 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>que[i].x>>que[i].y;que[i].id=i;//离线
		if(que[i].x>que[i].y)swap(que[i].x,que[i].y);
	}sort(que+1,que+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(i==1 || que[i].x != que[i].y){
			dj(que[i].x);
		}ans[que[i].id]=dis[que[i].y];
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
