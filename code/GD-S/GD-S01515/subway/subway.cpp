#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int c,n,m,d,q;
const int N=5e5+5,M=1e7+5;
vector<int>g2[505],a;
int A[M];
struct edge{
	int w,v;
//	bool operator> (edge &A,edge &B)const{
//	return A.w>B.w;
//	}
};
vector<pair<int,int>>b[N],g1[M];
void dfs(int st,int en){
	int ans=0;
	ans=a[st-1]+a[en-1];
	priority_queue<pair<int,int>>q;
	int cnt[m*n+5];
	int f[m*n+5];
	for(int i=1;i<=m*n;i++)cnt[i]=1e9,f[i]=0;
	for(int i=st;i<=m*n;i+=m){
		q.push({-i,-A[i]});
	    cnt[i]=A[i],f[i]=1;
	}
	while(!q.empty()){
		auto [now,w]=q.top();
		now=-now,w=-w;
	//	cout<<"now:"<<now<<' '<<w<<endl;
		q.pop();
		for(auto [v,ww]:g1[now]){
			//if(f[v])continue;
			if(v%m==en)ww+=A[v];
		//	cout<<v<<' '<<ww<<endl;
		//	cout<<now<<' '<<cnt[now]<<endl;
			if(cnt[v]>cnt[now]+ww){
				cnt[v]=cnt[now]+ww;
				if(f[v]==0)q.push({-v,-cnt[v]});
			}
			f[v]=1;
		}
	}
//	cout<<en;
	int now=1e9;
	for(int i=en;i<=m*n;i+=m){
       // printf("ansi:%d   ans%d\n",i,cnt[i]);
		now=min(cnt[i],now);
	}
	printf("%d\n",ans+now);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	vector<edge>g[m];
	for(int i=1;i<=n;i++){
		int x,sy;
		scanf("%d",&x);
	    //int now[x+5];
		for(int j=1;j<=x;j++){
			int l,r;scanf("%d%d",&l,&r);
			b[l].push_back({i,r});
			A[m*(i-1)+l]=r;
		//	now[j]=l;
			if(j==1)sy=l;
			else{
				g1[m*(i-1)+l].push_back({m*(i-1)+sy,0});
				g1[m*(i-1)+sy].push_back({m*(i-1)+l,0});
				sy=l;
			}
		}
//		for(int v=1;v<=x;v++){
//			for(int u=1;u<=x;u){
//				if(v==u)continue;
//				g1[m*(i-1)+u].push_back({m*(i-1)+v,0)};
//			}
//		}
	}
//	for(int i=1;i<=m*n;i++){
//		printf("i:%d A:%d\n",i,A[i]);
//		if(g1[i].size()){
//			cout<<i<<":";
//			for(auto [v,w]:g1[i]){
//				printf("%d w:%d ",v,w);
//			}
//		cout<<endl;
//		}
//	}
//	cout<<"--------------------"<<endl;
	for(int i=1;i<=m;i++){
		for(auto [x,x1]:b[i]){
			for(auto [y,y1]:b[i]){
				if(x==y)continue;
				g1[m*(x-1)+i].push_back({m*(y-1)+i,y1+x1});
			}
		}
	}
//	for(int i=1;i<=m*n;i++){
//		if(g1[i].size()){
//			cout<<i<<":";
//			for(auto [v,w]:g1[i]){
//				printf("%d w:%d ",v,w);
//			}
//		cout<<endl;
//		}
//	}
	while(q--){
		int st,en;
		scanf("%d%d",&st,&en);
		dfs(st,en);
	}
	return 0;
}
