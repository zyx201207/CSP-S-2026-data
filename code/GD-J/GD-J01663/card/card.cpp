#include <bits/stdc++.h>
using namespace std;
int n, m, gameloop = 0, im;
vector<int> cd, ans;
int l, r, f;
deque<int> cq;
int main(){
	//ÌâÄ¿£ºcard
	ios :: sync_with_stdio(false);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> im;
		cd. push_back(im);
	}
	for(int i = 1; i <= m; i ++){
		ans. push_back(0);
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i, l = 1; j <= n; j ++, l ++){
			cq. push_back(cd[j]);
			f = 0;
			for(int k = 0; k < cq. size(); k ++){
				if(cq[l - 1] == cq[l - 2] && cq. size() > 2){
					im = cq[cq. size() - 1];
					cq. pop_back();
					cq. pop_back();
					cq. push_back(im);
					l --;
					f = 1;
				}
				else{
					break;
				}
			}
			if(f == 1){
				im = cq[cq. size() - 1];
				cq. pop_back();
				cq. pop_back();
				cq. push_back(im);
			}
		}
		for(int j = 1; j <= m; j ++){
			for(int q = 0; q < cq. size(); q ++){
				if(cq[q] == j){
					ans[j] ++;
					break;
				}
			}
		}
		for(int j = 0; j < cq. size(); j ++){
			cq. pop_back();
		}
	}
	for(int i = 1; i <= m; i ++){
		cout << ans[i] << " ";
	}
	return 0;
}
