#include<bits/stdc++.h>
using namespace std;
long long c,t;
void solve(){
	long long n,d,x[50005];
	cin>>n>>d;
	 for(int i=1;i<=n;i++){
	 	cin>>x[i];
	 }
	cout<<n%d+1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
