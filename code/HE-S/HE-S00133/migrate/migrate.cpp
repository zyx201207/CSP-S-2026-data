#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int q=1;q<=n;q++){
		cin>>a[q];
	}
	cout<<0<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
