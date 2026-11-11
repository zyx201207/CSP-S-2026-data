#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[300005];
vector<int> s;
bool flag[300005];
int main(){
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int new_n = unique(a+1, a+n+1)-a-1;
	erase(a+new_n+1, a+n+1);
	/*
		for(int i = 1; i <= n; i++){
			s.clear();
			memset(flag, 0, sizeof(flag));
			for(int j = i; j <= n; j++){
				for(int k = 0; k < s.size(); k++){
					if(s[k] == a[j]){
						for(int l = k; l < s.size(); l++){
							s.pop_back();
						}
						break;
					}
				}
				s.push_back(a[j]);
			}
			for(int j = 0; j < s.size(); j++){
				if(!flag[j]){
					ans[j]++;
					flag[j] = true;
				}
			}
		}
	}*/
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ans[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
