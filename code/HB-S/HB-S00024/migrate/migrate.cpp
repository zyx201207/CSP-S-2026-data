#include <bits/stdc++.h>
using namespace std;
int c,t;
int arr[2000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>arr[i];
		int cha = arr[2]-arr[1];
		if(d<cha*2){
			cout<<0<<'\n';
			continue;
		}
		int minlen=d/cha+d/2;
		long long ans = 0;
		for(int len=minlen;len<n;len+=d/cha){
			ans += n-len;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
