#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int x[2000005];
void solve(int c){
	int n,d,len=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c==0 || c==11 || c==12){
		len=x[2]-x[1];
		if(len>d) cout<<"0\n";
		else cout<<n*(n-1)/2<<"\n";
	}else cout<<"0\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve(c);
	return 0;
}
