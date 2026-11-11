#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct stu{
	int u,v,next;
}t[2*N];
int n,k,h[N],xm=1;
int s[N],tq[N],ans;
bool tq2[N];
void auv(int u,int v){
	t[xm]={u,v,h[u]};
	h[u]=xm;
	xm++;
	t[xm]={v,u,h[v]};
	h[v]=xm;
	xm++;
}
void bfs(){
	int maxn=0;
	queue<int> q;
	for(int i=1;i<=k;i++){
		q.push(s[i]);
		tq2[s[i]]=1;
	}
	int tqk=k;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=t[i].next){
			int v=t[i].v;
			if(tq2[v]==0){
				tq2[v]=1;
				q.push(v);
				tq[v]=tq[u]+1;
				maxn=max(maxn,tq[v]);
			}else if(tq[v]==0&&tq[u]==0){
				tqk--;
			}
		}
	}
	if(tqk>2){
		return;
	}
	ans=min(ans,maxn);
}
void f(int i,int x){
	if(x==k){
		memset(tq,0,sizeof(tq));
		memset(tq2,0,sizeof(tq2));
		bfs();
		return;
	}
	if(k-x>n-i+1) return;
	s[x+1]=i;
	f(i+1,x+1);
	s[x+1]=0;
	f(i+1,x);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,cs;
	cin>>c>>cs;
	while(cs--){
		xm=1;
		memset(t,0,sizeof(t));
		memset(h,0,sizeof(h));
		memset(tq,0,sizeof(tq));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			auv(u,v);
		}
		ans=INT_MAX;
		f(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
