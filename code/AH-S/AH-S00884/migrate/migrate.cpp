#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long ans=1;
		for(int i=1;i<=(n-4);i++){
			ans*=2;
		} 
		cout<<ans<<'\n';
	}
	return 0;
}

