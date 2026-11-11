#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int x[1001],y[1001];
	int c,m,n,d,q,r,t,k,p;
	int w[1001],kl[1001][1001];
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<=n;i++){
		cin>>k;
		for(int j=0;j<2*k;j++){
			cin>>kl[i][j];
		}
	}
	for(int i=0;i<r;i++){
		cin>>x[i]>>y[i];
	}
	
} 
