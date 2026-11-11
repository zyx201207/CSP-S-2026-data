#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],dp[2][N],ans;
vector<int> v;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		vector<int> k;
		for(int j=0;j<v.size();j++){
			int x=v[j];
			if(x&(1ll<<i)){
				k.push_back(x);
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=(1ll<<i);
			v=k;
		}
	}
	cout<<ans;
	return 0;
} 
