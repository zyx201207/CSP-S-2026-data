#include<bits/stdc++.h>
using namespace std;
int n,t;
const int N=5e5+50;
int a[N];
inline void solve(){
	int n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<"a"<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>t;
	while(t--){
		solve();
	}
	return 0;
}
