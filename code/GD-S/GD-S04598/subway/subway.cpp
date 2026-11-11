#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e4+10;
int cc;
int n;
int m;
int d;
int q;
int w[M];
int a[N][M];
int t[N][M];
int k[N];
int head[M],cnt,dis[M];
struct ques{
	int id,first,second,ans;
}que[M];
queue<int>Q;
struct edge{
	int v,c,nxt;
}e[5000000];
void make_edge(int u,int v,int c){
	e[++cnt].v=v;
	e[cnt].c=c;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool cmp(ques x,ques y){
	return x.first<y.first;
}
bool ccmp(ques x,ques y){
	return x.id<y.id;
}
void dj(int s){
	while(Q.size()){
		Q.pop();
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	Q.push(s);
	dis[s]=0;
	while(Q.size()){
		int u=Q.front();
		Q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			int c=e[i].c;
			if(dis[v]>dis[u]+c){
				dis[v]=dis[u]+c;
				Q.push(v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(j==l){
					continue;
				}
				make_edge(a[i][j],a[i][l],t[i][j]+t[i][l]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>que[i].first>>que[i].second;
		que[i].id=i;
	}
	sort(que+1,que+1+q,cmp);
	for(int i=1;i<=q;){
		dj(que[i].first);
		int j=i;
		while(que[j].first==que[i].first){
			que[j].ans=dis[que[j].second]+w[que[j].first]+w[que[j].second];
			j++;
		}
		cout<<i<<endl;
		i=j;
	}
	sort(que+1,que+1+q,ccmp);
	for(int i=1;i<=q;i++){
		cout<<que[i].ans<<endl;
	}
	return 0;
} 
