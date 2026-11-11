#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long c,n,m,d,q,x[N],y[N];
long long w[N],a[1001][1001],t[1001][1001],subway[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>subway[i];
		for(int j=1;j<=subway[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
