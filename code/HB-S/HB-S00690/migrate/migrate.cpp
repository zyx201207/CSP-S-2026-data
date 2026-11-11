#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
int c,T,n,d,x[2000085];
void solveA() {
	int s=x[2]-x[1];
	int g=d/s;
	if(g==1||g==0||g>=n-1) {cout<<0<<'\n';}
	else if(g==2){
		cout<<n-3<<'\n';
	} else {
		cout<<n+1-2*g<<'\n';
	}
}
void solve() {
	cout<<0<<'\n';
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		bool specialA=true;
		for(int i=1;i<=n;++i) {
			cin>>x[i];
			if(x[i]-x[i-1]!=x[i-1]-x[i-2]&&i>=3) specialA=false;
		}
		if(n<=3) cout<<0<<'\n';
		else if(specialA) solveA();
		else if(n<=5000) solve();
	}
	return 0;
}
