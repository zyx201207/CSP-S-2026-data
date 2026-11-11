#include<bits/stdc++.h>

using namespace std;

using ll=long long;

using db=double;

#define int ll

#define endl '\n'

const int N = 2e6+8;
int c;
int n,d;
int a[N];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(c==11||c==12){
		int cha=a[n]-a[n-1];
		int sz=d/cha;
		sz*=2;
		if(sz>n||sz<=2) cout<<0<<endl;
		else cout<<max(ll(0),n-sz+1)<<endl;
	}
//	if(n<=300){
//		int ans=0;
//		for(int l=1;l<=n;l++){
//			for(int r=l+1;r<=n;r++){
//				
//			}
//		}
//		cout<<ans<<endl;
//	} 
	
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int t; cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}



