#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,kt[500009],zt[509][500009],jh[2][100009],ans[100009];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>kt[i];
	}
	for(ll i=1;i<=n;i++){
	    ll k;
	    cin>>k;
	    for(ll j=1;j<=k;j++){
	    	cin>>zt[i][j];
		}
	}
	for(ll r=1;r<=q;r++){
		cin>>jh[0][r]>>jh[1][r];
		
	}
    
//	0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
return 0;
} 
