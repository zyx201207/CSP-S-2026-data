//GZ-S00045 王子晨 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int,int>
#define pri priority
#define vec vector

#define rep(i,low,up) for(int i=low;i<=up;i++)
#define per(i,up,low) for(int i=low;i<=up;i++)

/*
thinking:
骗特殊节点分 A 
running:

*/
const int N=1e8;

int n,d;
vec<ll> site(N),p(N);

int i,j,k;

void solve(){
	cin>>n>>d;
	rep(i,1,n){
		cin>>site[i];
	}
	ll l=site[2]-site[1];
	if(2*l>d){
		cout<<0<<endl;
		return;
	}
	ll x=d/l;
	
	cout<<n-x<<endl;
	return;
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	int c,t;
	cin>>c>>t;
	while(t--){
		
		solve();
	}
	return 0;
}
