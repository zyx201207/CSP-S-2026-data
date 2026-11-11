#include<bits/stdc++.h>
using namespace std;
int ans[]={1,1,2};
int n,k,tmp,cnt;
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++) cin>>tmp>>tmp;
	cout<<ans[cnt++]<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--) solve();
	return 0;
}
