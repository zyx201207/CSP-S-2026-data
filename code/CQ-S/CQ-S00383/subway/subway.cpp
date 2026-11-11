#include<bits/stdc++.h>
using namespace std;
struct star{
	int to;
	int nxt;
	int val;
};
struct node{
	int ans;
	int p;
	bool operator < (const node u) const {
		return ans>u.ans;
	}
};
int head[500999];
star st[1000050];
int cnt[500999];
int dij[500999];
bool vis[500999];
int u=0;
priority_queue<node> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q,a,b,k;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",&cnt[i]);
	}
	int T;
	for(int i=1;i<=n;i++){
		scanf("%d",&T);
		for(int j=1;j<=T;j++){
			scanf("%d%d",&a,&k);
			u++;
			st[u]={a,head[i+m],k};
			head[i+m]=u;
			u++;
			st[u]={i+m,head[a],k};
			head[a]=u;
		}
	} 
//	for(int i=1;i<=n+m;i++){
//		cout<<"Case "<<i<<": \n"; 
//		for(int j=head[i];j;j=st[j].nxt){
//			cout<<st[j].to<<' '<<st[j].val<<'\n';
//		}
//	}
	while(Q--){
		cin>>a>>b;
		while(!q.empty()){
			q.pop();
		}
		for(int i=1;i<=n+m;i++){
			vis[i]=false;
			dij[i]=1e9+7;
		}
		dij[a]=0;
		vis[a]=true;
		q.push({0,a});
		while(!q.empty()){
			node op=q.top();
			q.pop();
			dij[op.p]=op.ans;
			for(int i=head[op.p];i;i=st[i].nxt){
				if(!vis[st[i].to]&&dij[st[i].to]>dij[op.p]+st[i].val){
					vis[st[i].to]=true;
					q.push({dij[op.p]+st[i].val,st[i].to});
				}
			}
		}
		cout<<dij[b]+cnt[a]+cnt[b]<<'\n';
	}	
	return 0;
}
