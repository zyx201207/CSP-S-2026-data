#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n,m;
bool chk(int x){
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=((a[i]&x)==x);
	return cnt>=m;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=30;i>=0;i--)
		if(chk(ans|(1<<i))) ans+=(1<<i);
	cout<<ans<<'\n';
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
	return 0;
}
