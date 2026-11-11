#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll>a[505],b[500005],dd[500005];
ll n,m,k[505],c,q,d,tk[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tk[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
		    ll x;
		    cin>>x;
		    a[i][j]=x;	
		    ll y;
		    cin>>y;
		    b[a[i][j]][i]=y;
		}
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
		    for(int o=1;o<=k[i];o++){
				if(j==o) continue;
				int p=a[i][j];
		        int q=a[i][o];
		        ll w=b[p][i]+b[q][i];
		        if(dd[p][q]!=0){
				   dd[p][q]=min(dd[p][q],w);
				   dd[q][p]=min(dd[q][p],w);
			    }
		        else{
				   dd[p][q]=w;
				   dd[q][p]=w;
			    } 
			}
		}
    }
    for(int i=1;i<=m;i++){
	    for(int j=1;j<=m;j++){
		    for(int l=1;l<=m;l++){
				if(i!=j&&l!=i&&l!=j&&dd[i][l]!=0&&dd[l][j]!=0){
					if(dd[i][j]!=0){
						dd[i][j]=min(dd[i][l]+dd[l][j],dd[i][j]);
					    dd[j][i]=dd[i][j];
					}
					else{
					    dd[i][j]=dd[i][l]+dd[l][i];
					    dd[j][i]=dd[i][j];	
					}
				}
		    }	
		}	
	}
	while(q--){
	   ll x,y;
	   cin>>x>>y;
	   cout<<tk[x]+dd[x][y]+tk[y]<<endl;
	}
    return 0;
}
