#include<bits/stdc++.h>
using namespace std;
const int N=2e6+60;
long long n,d,a[N],dc;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=1;
	for(int i=2;i<=n;i++){
		if(i==2) dc=a[i]-a[i-1];
		else if(a[i]-a[i-1]!=dc){
			f=0;break;
		}
	}
	if(f){
		if(d/dc<2){
			cout<<0<<'\n';
			return ;
		}
		if(n-(d/dc+d/dc-1)<=0) cout<<0<<'\n';
		else cout<<n-(d/dc+d/dc-1)<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
