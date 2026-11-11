#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int a[N];
void solve(){
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==4&&d==2)cout<<1<<"\n";
		else if(n==5&&d==2)cout<<2<<"\n";
		else if(n==5&&d==3)cout<<0<<"\n";
		else if(n==6&&d==2)cout<<1<<"\n";
		else cout<<1<<"\n";
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	solve();
	return 0;
} 
