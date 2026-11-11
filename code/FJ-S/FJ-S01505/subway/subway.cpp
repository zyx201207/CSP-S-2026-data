#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1000005],a[10005][10005],t[10005][10005],k[10000005],x,y,p;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=k[i];j++){
			for(int o=i+1;o<=n;o++){
				for(int l=1;l<=k[o];l++){
					if(a[i][j]==a[o][l]){
					   p=a[i][j];
					}
				}
			}
		}
	}
	while(q--){
		  cin>>x>>y;
		  bool f=false;
		  for(int i=1;i<=n;i++){
		  	  bool f=false,d=false;
		  	  for(int j=1;j<=k[i];j++){
		  	  	  if(a[i][j]==x){
		  	  	  	 f=true;
				   }
				   if(a[i][j]==y){
				   	  d=true;
				   }
			  }
			  if(f && d){
			  	 cout<<w[x]+w[y]+t[i][x]+t[i][y];
			  	 f=true;
			  	 break;
			  }
		  } 
	}
	return 0;
}
