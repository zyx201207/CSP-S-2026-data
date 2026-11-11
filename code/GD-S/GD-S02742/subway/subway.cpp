#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k,w[1000005],r[1000005],t[1000005];
int x,y;
int mapp[7001][7001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int a=1;a<=m;a++){
		for(int b=1;b<=m;b++)
		if(a==b) mapp[a][b]=0;
		else mapp[a][b]=1e9+5;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>r[j]>>t[j];
		for(int a=1;a<=k;a++){
			for(int b=1;b<=k;b++){
		    mapp[r[a]][r[b]]=min(mapp[r[a]][r[b]],t[a]+t[b]);
		    //cout<<mapp[r[a]][r[b]]<<endl;
		}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
		    	if(i==j||j==k||i==k) continue;
				mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]); 
			}
		}
	}	
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<mapp[i][j]<<" ";
		
		}	cout<<endl; 
	}*/
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	    cout<<mapp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
