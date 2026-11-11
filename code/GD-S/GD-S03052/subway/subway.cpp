#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int c,n,m,d,q;
int w[N];
long long t[505][N],a[505][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	}
    while(q--){
    	int x,y;
    	cin>>x>>y;
    	long long minx=1e18,miny=1e18;
    	for(int i=1;i<=n;i++){
    		if((t[i][x]!=0)&&(t[i][y]!=0)){
    			minx=min(minx,t[i][x]);
				miny=min(miny,t[i][y]);
			}
		}
		if(miny==1e18)miny=0;
		if(minx==1e18)minx=0;
    	cout<<w[x]+minx+miny+w[y]<<endl;
	}
	return 0;
}
