#include<bits/stdc++.h>
using namespace std;
int mp[500005], ans[300005], sta[500005], stb[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	bool fla = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> mp[i];
		if(mp[i] < mp[i - 1]){
			fla = 0;
		}
	}
	if(n <= 500){
		int d = 0x3f3f3f3f, l = 0;
		for(int t = 1; t <= n; t++){
			int tpa = 0;
			for(int i = t; i <= n; i++){
				int tpb = 1;
				stb[tpb] = mp[i];
				while(sta[tpa] != mp[i] && tpa){
					tpb++;
					stb[tpb] = sta[tpa];
					tpa--;
				}
				if(tpa == 0){
					while(tpb >= 1){
						tpa++;
						sta[tpa] = stb[tpb];
						tpb--;
					}
				}
			}
			while(tpa >= 1){
//				cout << sta[tpa] << " ";
				ans[sta[tpa]]++;
				tpa--;
			}
//			cout << "\n";
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i] << " ";
		}
	} else if(fla){
		for(int i = 1; i <= n; i++){
			if(mp[i + 1] != mp[i]){
				ans[mp[i]] = i;
			}
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i] << " ";
		}
	} else if(m <= 2){
		for(int i = 1; i <= n; i++){
			if(mp[i] != mp[n]){
				ans[mp[i]]++;
			}
		}
		if(mp[n] == 1){
			cout << n << " " << ans[2];
		} else {
			cout << ans[1] << " " << n;
		}
	}
	return 0;
}
