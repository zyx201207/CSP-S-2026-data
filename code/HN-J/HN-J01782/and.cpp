#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>t;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		t.push_back(x);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(auto x:t){
			if((x>>i)&1)cnt++;
		}
		if(cnt>=m){
			ans|=(1<<i);
			vector<int>tc;
			for(auto x:t){
				if((x>>i)&1)tc.push_back(x);
			}
			swap(t,tc);
		}
	}
	cout<<ans;
	return 0;
}

