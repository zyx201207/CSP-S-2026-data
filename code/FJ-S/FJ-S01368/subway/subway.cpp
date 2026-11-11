#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long long c,n,m,d,q;
long long w[500050];
vector<long long> a[1000],t[1000];
struct p{
	long long id;
	long tm;
};
vector<p>passed[500050];
long long cntp[500050];
long long cost[1000][1000];
bool cmp(p x,p y){
	return x.id<y.id;
}
//long long exittm[505][500050];
bool ok[505][500050];
long long start,ed;
//long long finalans;
//void dfs(long long nw,long long len,long long s){
//	if(len>=ans[nw])return;
//	ans[nw]=len;
////	cout<<ed<<' '<<nw<<' '<<ok[ed][nw];
//	if(ok[nw][ed]){
//		finalans=min(finalans,(long long)(len+w[start]+exittm[nw][ed]+exittm[s][start]+w[ed]));
//		return;
//	}
//	for(long long i=1;i<=n;i++){
//		if(cost[i][nw]!=2e9+10){
//			dfs(i,cost[nw][i]+len,s);
//		}
//	}
//}
struct node{
	long long id;
	long long val;
};
vector<node> e[505];
bool operator<(node x,node y){
	return x.val<y.val;
}
bool operator>(node x,node y){
	return x.val>y.val;
}
priority_queue<long long,vector<node> > que;
long long dis[505][505];
void dij(long long x){
	for(long long i=1;i<=n;i++){
		if(i!=x)dis[x][i]=1e18;
		else dis[x][i]=0;
	}
	que.push({x,0});
	while(!que.empty()){
		long long nw=que.top().id,ntm=que.top().val;
		que.pop();
		for(node nxt:e[nw]){
			if(ntm+nxt.val<dis[x][nxt.id]){
				dis[x][nxt.id]=ntm+nxt.val;
				que.push({nxt.id,ntm+nxt.val});
			}
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		a[i].resize(k+1);
		t[i].resize(k+1);
		for(long long j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
			passed[(long long)a[i][j]].push_back({i,t[i][j]});
			cntp[a[i][j]]++;
//			passed[a[i][j]][cntp[a[i][j]]].id=i;
//			cout<<a[i][j]<<' '<<cntp[a[i][j]]<<' '<<i<<edl;
//			passed[a[i][j]][cntp[a[i][j]]].tm=t[i][j];
//			ok[i][a[i][j]]=1;
//			exittm[i][a[i][j]]=t[i][j];
		}
	}
	for(long long x=1;x<=m;x++){
		sort(passed[x].begin(),passed[x].end(),cmp);
//		for(long long i=0;i<cntp[x];i++){
//			for(long long j=i+1;j<cntp[x];j++){
//				if(cost[passed[x][i].id][passed[x][j].id]==0)cost[passed[x][i].id][passed[x][j].id]=2e9+10;
//				cost[passed[x][i].id][passed[x][j].id]=min(cost[passed[x][i].id][passed[x][j].id],(long long)(passed[x][i].tm+passed[x][j].tm));
//				cost[passed[x][j].id][passed[x][i].id]=cost[passed[x][i].id][passed[x][j].id];
//			}
//		}
		for(p i:passed[x]){
			for(p j:passed[x]){
				if(cost[i.id][j.id]==0)cost[i.id][j.id]=2e9+10;
				cost[i.id][j.id]=min(cost[i.id][j.id],(long long)(i.tm+j.tm));
				cost[i.id][j.id]=cost[i.id][j.id];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			node tmp;
			tmp.id=j;
			tmp.val=cost[i][j];
			e[i].push_back(tmp);
			tmp.id=i;
			e[j].push_back(tmp);
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			cout<<cost[i][j]<<' ';
//		}
//		cout<<edl;
//	}
	long long out=1e18+10;
	for(long long i=1;i<=n;i++)dij(i);
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	} 
	for(long long x=1;x<=q;x++){
		cin>>start>>ed;
		out=1e18+10;
//		for(long long i=0;i<cntp[start];i++){
//			for(long long j=0;j<cntp[ed];j++){
//				out=min(out,(long long)(dis[passed[start][i].id][passed[ed][j].id]+w[start]+w[ed]+passed[start][i].tm+passed[ed][j].tm));
//			}
//		}
		for(p i:passed[start]){
			for(p j:passed[ed]){
				out=min(out,(long long)(dis[i.id][j.id]+w[start]+w[ed]+i.tm+j.tm));
			}
		}
		cout<<out<<endl;
////		cout<<passed[start][1].id<<'*'<<edl;
//		out=1e18+10;
//		for(long long i=1;i<=cntp[start];i++){
//			
//			for(long long j=1;j<=n;j++)ans[j]=1e18+10;
//			finalans=1e18+10;
////			cout<<passed[start][i].id<<edl;
//			dfs(passed[start][i].id,0,passed[start][i].id);
//			out=min(out,finalans);
//		}
//		cout<<out<<endl;
	}
	
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
