#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m,a[N],ans[N];
int cnt[N];
int pos[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	
	for(int i = n; i >= 1; i--){
		if(pos[a[i]] == 0)pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		vector<int> v;
		for(int j = i; j <= n; j++){
			int val = a[j];
			while(cnt[val]) {
				cnt[v.back()]--;
				v.pop_back();
			}
			cnt[val] = 1;
			v.push_back(val);
			
			if(pos[a[j]] > j) j = pos[a[j]];			
		} 
		for(const int x : v){
			cnt[x]--;
			ans[x]++;
		}
	}
	
	for(int i = 1; i <= m; i++) cout<<ans[i]<<" ";
	return 0;
} 
