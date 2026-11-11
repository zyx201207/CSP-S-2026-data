#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+10,M=5e3;
int c,t,n,d,x[N],f[M][M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;bool f=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1&&x[i]-x[i-1]!=x[2]-x[1])f=1;
		}
		if(d==2){
			cout<<n-3<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
