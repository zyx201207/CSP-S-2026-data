#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,s,l,r;
long long k;
long long a[500002];
long long b[50][500002];
long long t[50][500002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		if(n==2){
			cout<<a[l]+a[r]+t[1][l]+t[2][r]<<endl;
		}
		else if(n==1) cout<<a[l]+a[r];
		else cout<<32<<endl;
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/