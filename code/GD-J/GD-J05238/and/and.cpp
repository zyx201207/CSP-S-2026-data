#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define int long long
int n,m,a[N],cnt[50],ans;
set<int>chs;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		chs.insert(i);
		for(int j = 31; j >= 0; j--){
			if(a[i]>>j&1)cnt[j]++;
		}
	}
	for(int i = 31; i >= 0; i--){
		if(cnt[i]>=m){
			ans|=(1ll<<i);
			vector<int>v;
			for(int k : chs){
				if((a[k]>>i&1)==0){
					v.push_back(k);
					for(int j = i; j >= 0; j--){
						if(a[k]>>j&1)cnt[j]--;
					}
				}
			}
			for(int k : v){
				chs.erase(k);
			}
		}
	}
	cout << ans;
	return 0;
} 
