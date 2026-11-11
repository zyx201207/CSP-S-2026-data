#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 2;
int s[maxn], id[maxn];
int ans[maxn];
int n, m;
bool flag;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		if(s[i] < s[i - 1])
			flag = 1;
	}
	if(m <= 2){
		for(int i = 1; i <= n; i++)
			if(s[i] == s[n])
				ans[s[i]]++;
			else{
				ans[s[i]]++;
				ans[s[n]]++;
			}
		cout << ans[1] << ' ' << ans[2];
		return 0;
	}
	if(!flag){
		for(int i = 1; i <= n; i++)
			id[s[i]] = i;
		for(int i = 1; i <= m; i++)
			cout << id[i] << ' ';
	}
    return 0;
}
//Trick||Treat!

