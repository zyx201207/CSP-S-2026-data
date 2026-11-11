#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

struct Node{
	int val, id;
}cnt[N];
int n, m;
int a[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		string s;
		memset(cnt, 0, sizeof(cnt));
		for (int j = i; j <= n; j++){
			cnt[a[i]].val++;
			cnt[a[i]].id = s.size();
			if (cnt[a[i]].val > 1){
				if (cnt[a[i]].id = 0){
					for (int i = 1; i <= s.size(); i++){
						cnt[a[i]].val = 0;
						cnt[a[i]].id = 0;
					}
					s = (char)(a[i] + '0');
					cnt[a[i]].id = 0;
					cnt[a[i]].val = 1;
				}else{
					for (int i = 1; i <= cnt[a[i]].id + 1; i++){
						cnt[a[i]].val = 0;
						cnt[a[i]].id = 0;
					}
					s = s.substr(0, cnt[a[i]].id);
					cnt[a[i]].val = 1;
					cnt[a[i]].id = s.size() - 1;
					s += (char)(a[i] + '0');			
				}
			}else{
				s += (char)(a[i] + '0');	
			}
		}
		cout << s << '\n';
	}
	return 0;
}
