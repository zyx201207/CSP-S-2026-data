#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> chs;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int _ = 1;//cin >> _;
	while(_--){
		int n,m;cin >> n >> m;
		for(int i=1;i<=n;i++){
			int x;cin >> x;chs.push_back(x);
		}
		int ans = 0;
		for(int now=31;now >= 0;now--){
			vector<int> wchs;
			for(int x:chs)
				if((x >> now) & 1) wchs.push_back(x);
			if(wchs.size() >= m)
				swap(chs,wchs),wchs.clear(),ans = ans + (1<<now);
		}
		cout << ans;
	}
	return 0;
}

