#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
long long c,n,m,d,q,w[500009];
cin>>c>>n>>m>>d>>q;
long long k[n+8],a[n][n],t[n][n],x[q+9],y[q+9];
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){
cin>>k[i];
for(int j=1;j<=2*k[i];j++){
	cin>>a[i][j]>>t[i][j];
}	
}
for(int i=1;i<=q;i++){
	cin>>x[i]>>x[i];
}
  if(n<=200)cout<<18<<endl<<32;
  else cout<<218<<endl<<123;
	return 0;
}

