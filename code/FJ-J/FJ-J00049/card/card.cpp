#include <bits/stdc++.h>
using namespace std;

int n, m, a[500002], f[500002], ans[300002], lans[300002], lf[500002];
int nxt[500002];
bool b[500002];

int main(){
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	for(int beg = 1; beg <= n; beg++){
				
		memset(f, -1, sizeof(f));
		memset(lf, -1, sizeof(lf));
		memset(ans, 0, sizeof(ans));
		memset(b, false, sizeof(b));
		//memset(nxt, -1, sizeof(nxt));
		for(int i = beg; i <= n; i++){
			if(i == n)nxt[i] = -1;
			nxt[i] = i + 1;
		}
		
		for(int i = beg; i <= n; i++){
			if(f[a[i]] != -1){
				for(int j = f[a[i]]; j <= i - 1; j = nxt[j]){
					if(b[j] == false){
						b[j] = true;
						ans[a[j]]--, f[a[j]] = lf[a[j]];
					}
					//if(beg == 3)cout << "uibuibuib\n";
				}
				nxt[ f[ a[i] ] - 1 ] = i;
			}
			ans[a[i]]++;
			//if(beg == 3)if(a[i] == 3)cout << "biubiubiu\n";
			lf[a[i]] = f[a[i]];
			f[a[i]] = i;
		}
		for(int i = 1; i <= m; i++){
			//if(ans[i] < 0)cout << "?????????qwq" << beg << " " << i << "\n";
			lans[i] += ans[i];
		}
		//if(ans[1] == 0)cout << "01" << " " << beg << "\n";
		
	}
	for(int i = 1; i <= m; i++)cout << lans[i] << " ";
	
	return 0;
}

/*
5 3
1 2 3 2 1
*/

