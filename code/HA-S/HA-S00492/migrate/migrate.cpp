#include <bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

const int N=2e6+5;

void fre(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}

int c,t,a[N];

void solve(){
	int n,l;
	cin>>n>>l;
	F(i,1,n){
		cin>>a[i];
	}
	if(c>=11&&c<=12){
		int d=a[2]-a[1];
		if(l/d<2)cout<<0<<endl;
		else if((l/d)*2-1>n)cout<<0<<endl;
		else cout<<n-(l/d)*2+1<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	cin>>c>>t;
	while(t--){
		solve();
	}




	Luogu _DEQUE_;
}

