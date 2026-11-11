#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c;
long long n,d,x[N],minn;
void solve(){
	cin>>n>>d;
	for(long long i=1;i<=n;i++) cin>>x[i];
	cout<<n/(d*2)+n%(d*2)<<'\n';
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrite.out","w",stdout); 
	ios::sync_with_stdio(0) ,cin.tie(0),cout.tie(0);
	int _=1;
	cin>>c>>_;
	while(_--){
		solve();
	}
	return 0;
}
