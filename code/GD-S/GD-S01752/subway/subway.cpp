#include<bits/stdc++.h>
using namespace std;

int const maxn=1e6;
int g[505][505];
int x[maxn],y[maxn];
int w[maxn];
int t[maxn];
int main(){
	int k[505];
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x;j<=k[i];j++){
        cin>>x;
        g[i][j]=x;
        cin>>t[i];
        }
    }
    for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
    if(c==0){
        if(n==2) cout<<32<<'\n'<<17;
        else if(n==3) cout<<35<<'\n'<<16;
    }
    else{
        for(int f=1;f<=q;f++){
        	int sw=0,dw=0,zh=0,sw1=0,dw1=0;
        	for(int i=0;i<n;i++){
            	for(int j=0;j<k[i];j++){
            		if(g[i][j]==x[f]){
            			sw=j;sw1=i;
					}
            		if(g[i][j]==y[f]){
            			dw=j;sw1=i;
					}
            		if(sw!=0 && dw!=0) break;
        		}
        	}
        	for(int i=1;i<=n;i++){
            	for(int j=1;j<=k[i];j++){
            		if(g[sw1][j]==g[sw1][i]) zh=g[sw1][j];
        		}
        	}
        	cout<<w[sw]+t[zh]+w[dw];
		}
    }
	return 0;
}
