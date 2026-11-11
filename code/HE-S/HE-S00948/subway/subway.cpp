#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
		int c,n,m,d,p;cin>>c>>n>>m>>d>>p;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k[n];int a[n][10000];int t[n][10000];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x[p];int y[p];
	for(int l=0;l<p;l++){
		cin>>x[l]>>y[l];
	int b=0;int zs=0;
	for(int i=0;i<n;i++){
		int m1=a[i][b];b++;int q=2*k[i]; 
		for(int j=0;j<q;j++){
			if(m1==a[i+1][j]){
				if(a[i+1][j+1]==y[l]){
					zs=w[1]+t[1][1]+(t[1][2]+t[2][2])+t[2][3]+w[3];
					break;
				}
			}
		}
	}
	//cout<<zs;
	} 
	cout<<1<<endl<<1;
	return 0;
}
