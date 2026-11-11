#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500005],cnt[300005];
deque<ll>::iterator b[300005];
int main(){
	freopen("card5.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	deque<ll> desktop;
	deque<ll> heap(a+1,a+n+1),heap3;
	while(n--){
		desktop.clear();
		bitset<300005> have;
		memset(b,0,sizeof(b));
		while(heap.size()){
			ll x=heap.front();heap.pop_front();
			deque<ll> heap2;
			if(have[x]){
				while(desktop.end()-b[x])
					heap2.push_back(desktop.back()),desktop.pop_back();
				reverse(heap2.begin(),heap2.end());
				while(heap2.size())heap3.push_back(heap2.front()),heap2.pop_front();
			}
			desktop.push_back(x);
			b[x]=desktop.end()-1;
			have[x]=true;
		}
		while(desktop.size())heap3.push_back(desktop.front()),cnt[desktop.front()]++,desktop.pop_front();
		heap=heap3;
		heap.pop_front();
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
} 
