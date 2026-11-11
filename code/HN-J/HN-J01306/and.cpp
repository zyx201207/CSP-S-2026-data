#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>e;
	for(int i=1;i<=n;i++) e.push_back(i);
	for(int j=29;j>=0;j--){
		int cnt=0;
		vector<int>ep;
		for(auto i:e){
			if(((a[i]>>j)&1)==1){
				cnt++;
				ep.push_back(i);
			}
		}
		if(cnt>=m) e=ep;
	}
	int ans=(1ll<<30)-1;
	for(auto i:e) ans&=a[i];
	cout<<ans;
	return 0;
}

