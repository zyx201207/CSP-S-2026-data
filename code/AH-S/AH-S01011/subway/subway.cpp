#include<bits/stdc++.h>
using namespace std;
const int N=510;
int w[N],d[N][N],a[N][N],t[N][N];
vector<int>G[N];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
int c,n,m,d1,p,k,ks,js;
cin>>c>>n>>m>>d1>>p;
for(int i=1;i<=m;i++){
	cin>>w[i];
}	
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
		cin>>a[i][j]>>t[i][j];
	}
	for(int j=2;j<k;j++){
		G[a[i][j]].push_back(a[i][j-1]);
		G[a[i][j]].push_back(a[i][j+1]);
	}
	for(int j=1;j<=k;i++){
		for(int q=1;q<=k;j++){
			d[a[i][q]][a[i][j]]=w[q]+t[i][j]+t[i][q]+w[j];
			d[a[i][j]][a[i][q]]=w[q]+t[i][j]+t[i][q]+w[j];
		}
	}
	for(int j=1;j<=k;j++){
		for(int t:G[j]){
			for(int q=1;q<k;q++){
				if(!d[t][q]) d[t][q]=d[j][t]+d[j][q]-2*w[j];
				else d[t][p]=min(d[t][p],d[j][t]+d[j][q]-2*w[j]);
			}
		}
	}
}
for(int i=1;i<=p;i++){
	cin>>ks>>js;
	cout<<d[ks][js]<<endl;
}	
return 0;}
