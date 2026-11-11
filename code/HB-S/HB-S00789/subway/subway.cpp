#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
int c,n,m,d,q;
int k[22];
ll w1[N];
struct node{
	ll w2;
	int a;
}h[22][N];
struct wei{
	int h;
	int pos;
	ll sum;
};
int start,ed;
int bfs(int cen,int s){
    queue<wei>q;
    q.push({cen,s,w1[start]+h[cen][s].w2});
    while(!q.empty()){
		wei cur=q.front();
		q.pop();
		if(h[cur.h][cur.pos].a==ed){
			return cur.sum+w1[ed]+h[cur.h][cur.pos].w2;
		}
		if(cur.pos+1<=k[cur.h]){
			q.push({cur.h,cur.pos+1,cur.sum});
		}
		for(int i=1;i<=n;++i){
			if(i==cur.h)continue;
			for(int j=1;j<=k[i];++j){
				if(h[i][j].a==cur.pos){
					if(h[i][j].a==ed)q.push({i,j,cur.sum+h[i][j].w2+h[cur.h][cur.pos].w2});
					else q.push({i,j,cur.sum+h[cur.h][cur.pos].w2+h[i][j].w2});
				}
			}
		}
	}
	return -1;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
	start=0,ed=0;
    for(int i=1;i<=m;++i)cin>>w1[i];
    for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int u;
			ll t;
			cin>>u>>t;
			h[i][j].a=u;
			h[i][j].w2=t;
		}
	}
	while(q--){
	    cin>>start>>ed;
	    int minn=1e9;
	    for(int i=1;i<=n;++i){
			for(int j=1;j<=k[i];++j){
				if(h[i][j].a==start){
					int s=bfs(i,j);
					if(s!=-1)minn=min(minn,s);
					break;
				}
			}
		}
		cout<<minn<<"\n";
    }
    return 0;
}
