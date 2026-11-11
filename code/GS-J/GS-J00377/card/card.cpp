#include<bits/stdc++.h>
using namespace std;
map<int, int> all;
int a[500005];
struct Node{
	int q, p;
}mp[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		int h = 1;
		for(int j = i;j < n;j++){
			if(mp[a[j]].p){
				for(int x = 1;x <= m;x++){
					if(mp[x].q > mp[a[j]].q && mp[x].p){
						mp[x].q = 0;
						mp[x].p = 0;
					}
				}
			}else{
				mp[a[j]].p++;
				mp[a[j]].q = h;
				h++;
			}
		}
		for(int j = 1;j <= m;j++){
			if(mp[j].p){
				all[j]++;
			}
		}
		for(int x = 1;x <= m;x++){
			mp[x].p = 0;
			mp[x].q = 0;
		}
	}
	for(int j = 1;j <= m;j++){
		if(all[j])
			cout << all[j] << ' ';
	}
	return 0;
}
