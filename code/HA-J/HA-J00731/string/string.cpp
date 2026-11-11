#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
typedef long long ll;

ll d[maxn];
char s[maxn];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	
	for (int i = 1 ; i <= n ; ++ i){
		cin >> d[i] >> s[i];
	}
	
	ll cnt = 0;
	
	for (int i = 1 , j = n ; i < j ;){
		
		if (s[i] == s[j]){
			if (d[i] < d[j]){
				d[j] -= d[i];
				++ i;
			} else if (d[i] > d[j]){
				d[i] -= d[j];
				-- j;
			} else{
				++ i , -- j;
			}
			continue;
		}
		
		if (d[i] < d[j]){
			cnt += d[i];
			d[j] -= d[i];
			++ i;
		} else if (d[i] > d[j]){
			cnt += d[j];
			d[i] -= d[j];
			-- j;
		} else{
			cnt += d[i];
			++ i , -- j;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
