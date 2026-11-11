#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+10,N = 110;
struct node{
    int x, y;
}g[M][N];
int c, m, n, d, q, w[N],a[M][N],t[M][N],ans,k[M],vv[N];
void zdl(int u, int v, int s,int e){
	//cout<<u<<" "<<v<<endl;
    if(u == v){
        ans = min(ans, s);
        return;
    }
    if(s>ans){
        return;
    }
    for(int i = 1;i<=vv[u];i++){
        node b = g[u][i];
        int l = 0;
        if(b.x!=e){
           l = t[e][b.x];
        }
        zdl(a[b.x][b.y+1],v,s+l,b.x);
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i = 1;i<=n;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=m;i++){
		cin>>k[i];
        for(int j = 1;j<=2*k[i];j++){
            if(j%2==1){
                cin>>a[i][(j-1)/2];
                node h;
                h.x = i, h.y = j;
                g[a[i][j]][++vv[a[i][j]]]=h;

            }
            if(j%2==0) cin>>t[i][j/2];
        }
    }
    /*for(int i = 1;i<=m;i++){
		cout<<k[i]<<" ";
	    for(int j = 1;j<=2*k[i];j++){
		    if(j%2==1){
			    cout<<a[i][(j-1)/2]<<" ";
			}
			if(j%2==0) cout<<t[i][j/2]<<" ";
		}
		cout<<endl;
	}*/
    for(int i = 1;i<=q;i++){
        int u = -1, v = -1;
        cin>>u>>v;
        ans = w[u]+w[v]+t[1][u]+t[1][v];
        if(u!=-1&&v!=-1) {
			zdl(u,v,w[u]+w[v],u);
		}
		cout<<ans<<endl;

    }
    return 0;
}
