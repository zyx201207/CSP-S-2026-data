#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,s[N],ma=1,sum;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=2,j=1;i<=n;i++){
		sum+=(i-j)*(s[i]-s[i-1]);
		while(sum>m){
			sum-=(s[i]-s[j]);
			j++;
		}
		ma=max(ma,i-j+1);
	}
	cout<<ma;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
