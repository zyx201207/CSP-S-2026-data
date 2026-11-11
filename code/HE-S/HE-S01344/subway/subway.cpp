#include<bits/stdc++.h> 
using namespace std;
const int N=100010;
int a[N][N],w[N],x[N],y[N],t[N][N],c,n,m,d,q,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int i=1;i<=2k;i++){
		for(int i=1;i<=2k;i++){
			 cin>>a[i][j]>>t[i][j];
		}
	} 
	for(int i=1;i<=r;i++){
		cin>>x[i]<<y[i]; 
	}
	return 0;
}
