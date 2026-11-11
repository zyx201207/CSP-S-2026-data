#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
long long x[N];
bool ff(long long l,long long r,int n){
	for(int i=1;i<=n;i++){
		if(x[i]==r && x[i-1]!=l) return true;
	}return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		for(int j=1;j<=n;j++){
			long long l=x[j];
			long long r=l+(2*d-1);
			if(r>x[n]) break;
			if(ff(l,r,n)) ans++;
		}
			
		cout<<ans<<endl;
	}
	
	
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5



0 2
5  3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
