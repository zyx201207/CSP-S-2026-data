#include<bits/stdc++.h>
using namespace std;

long long a[200005];

void solve(){
	int n,m,jg;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	jg=a[1];
	for(int i=2;i<=m;i++){
		jg&=a[i];
	}
	cout<<jg;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
