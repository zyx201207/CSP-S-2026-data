#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector <int> all;
	int n,m;
	cin >> n >> m;
	int ans[m + 1];//tong
	int cnt[n];//card
	for(int i = 0;i < n;i++){
		cin >> cnt[n];
	}
	all.push_back(cnt[0]);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			bool flag = 0;
			int index;
			for(int z = 0;z < all.size();z++){
				if(all[z] == cnt[j]){
					index = z;
					flag = 1;
				}
			}
			if(flag){
				all.insert(index,cnt[n]);
			}else{
				all.push_back(cnt[n]);
			}
		}
		for(int i = 0;i < all.size();i++){
			ans[all[i]]++;
		}
		all.clear();
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' '; 
	}
	return 0;
}
