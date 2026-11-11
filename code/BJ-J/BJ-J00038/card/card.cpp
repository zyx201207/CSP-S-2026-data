#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
int a[N];
int ans[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		deque<int> b;
		vector<pair<bool, int> > vis(m + 1);
		for(int j = i; j <= n; j++){
            if(vis[a[j]].first == 1){
                int k = vis[a[j]].second;
                while(b.size() >= k){
                    int x = b.back();
                    vis[x] = {0, 0};
                    b.pop_back();
                }
            }
			b.push_back(a[j]);
			vis[a[j]] = {1, b.size()};
		}
		for(int i = 0; i < b.size(); i++){
            ans[b[i]]++;
		}
	}
	for(int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
	}
	return 0;
}
