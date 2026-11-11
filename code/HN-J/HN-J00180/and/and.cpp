#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

int const N=2e5+10;
int n,m,an[N],ans;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((an[i]&ans)!=ans) continue;
			cnt+=((an[i]>>k)&1);
		}
		if(cnt>=m) ans|=(1<<k);
	}
	cout<<ans;
	return ;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}

