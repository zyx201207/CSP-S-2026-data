#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
int c,t,n;
ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1) cout<<0<<'\n';
		else if(x[2]-x[1]>d/2) cout<<0<<'\n';
		else{
			int i=2;
			while(x[2]-x[1]<=d/i) i++;
			cout<<n-i<<'\n';
		}
	}
	return 0;
}
