#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

int const N=2e5+10;
int n,s[N],ans;
char c[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int num=min(s[l],s[r]);
		if(c[l]!=c[r]) ans+=num;
		s[l]-=num,s[r]-=num;
		if(!s[l]) l++;
		if(!s[r]) r--;
	}
	cout<<ans;
	return ;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}

