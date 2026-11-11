#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,cnt,ans;
vector<int> s,t;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x;
		s.push_back(x);
	}
	for(int i=29;i>=0;i--){
		cnt=0;
		for(int x:s){
			cnt+=((x>>i)&1);
		}
		if(cnt>=m){
			ans|=(1<<i);
			t=s;
			s.clear();
			for(int x:t){
				if((x>>i)&1) s.push_back(x);
			}
		}
	}
	cout<<ans;
	return 0;
}

