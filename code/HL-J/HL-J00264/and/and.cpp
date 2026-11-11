#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt[n];
	for(int i = 0;i < n;i++){
		cin >> cnt[i];
	}
	vector <int> ans;
	if(m == 2){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i == j) continue;
				ans.push_back(cnt[i] & cnt[j]);
			}
		}
		sort(ans.begin(),ans.end());
	}else{
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int z = 0;z < n;z++){
					if(i == j || j == z || i == z) continue;
					ans.push_back(cnt[i] & cnt[j] & cnt[z]);
				}

			}
		}
		sort(ans.begin(),ans.end());
	}
	cout << ans[ans.size()];
	return 0;
}
