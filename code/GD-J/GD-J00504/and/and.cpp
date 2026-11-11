#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

const int N = 200005;
int n,m;
int a[N];
int tr[N * 30][2],tot = 0;
int cnt[N * 30];
void insert(int x){
	int rt = 0;
	for(int i = 29;i >= 0;i--){
		int now = (x >> i) & 1;
		if(!tr[rt][now]) tr[rt][now] = ++tot;
		rt = tr[rt][now];
		cnt[rt]++;
	}
}
int ans = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i],insert(a[i]);
	vector<int> rt;
	rt.emplace_back(0);
	int ans = 0;
	for(int i = 29;i >= 0;i--){
		int sum = 0;
		for(auto x : rt) sum += cnt[tr[x][1]];
		if(sum >= m){
			ans += (1 << i);
			for(auto & x : rt) x = tr[x][1];
		}
		else{
			vector<int> tmp;
			for(auto x : rt){
				if(tr[x][0]) tmp.emplace_back(tr[x][0]);
				if(tr[x][1]) tmp.emplace_back(tr[x][1]);
			}
			rt.swap(tmp);
		}
	}
	cout << ans;
	return 0;
}