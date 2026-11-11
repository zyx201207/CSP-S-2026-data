#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2;
int s[maxn], flag[maxn];
int c[6];
int n, m;
int ans;
int x;
bool cmp(int x, int y){
	return x > y;
}
void f(){
	x = 1;
	for(int i = 1; i <= n; i++)
		if(s[i] + 1 != pow(2 , 0) && s[i] + 1 != pow(2 , 1) && s[i] + 1 != pow(2 , 2) && s[i] + 1 != pow(2 , 3) && s[i] + 1 != pow(2 , 4) && s[i] + 1 != pow(2 , 5) && s[i] + 1 != pow(2 , 6) && s[i] + 1 != pow(2 , 7) && s[i] + 1 != pow(2 , 8) && s[i] + 1 != pow(2 , 9) && s[i] + 1 != pow(2 , 10) && s[i] + 1 != pow(2 , 11) && s[i] + 1 != pow(2 , 12) && s[i] + 1 != pow(2 , 13) && s[i] + 1 != pow(2 , 14) && s[i] + 1 != pow(2 , 15) && s[i] + 1 != pow(2 , 16) && s[i] + 1 != pow(2 , 17) && s[i] + 1 != pow(2 , 18) && s[i] + 1 != pow(2 , 19) && s[i] + 1 != pow(2 , 20) && s[i] + 1 != pow(2 , 21) && s[i] + 1 != pow(2 , 22) && s[i] + 1 != pow(2 , 23) && s[i] + 1 != pow(2 , 24) && s[i] + 1 != pow(2 , 25) && s[i] + 1 != pow(2 , 26) && s[i] + 1 != pow(2 , 27) && s[i] + 1 != pow(2 , 28) && s[i] + 1 != pow(2 , 29) && s[i] + 1 != pow(2 , 30)){
			x = 2;
			break;
		}
	if(x == 1)
		return;
	
	for(int i = 1; i <= n; i++)
		if(s[i] != i - 1){
			x = 3;
			break; 
		}
	if(x == 2)
		return;
	
	for(int i = 1; i <= n; i++)
		if(s[i] > 4){
			x = 4;
			return;
		}
	return;
}
void check(){
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
		if(flag[i])
			cnt++;
	if(cnt != m)
		return;
	for(int i = 1; i <= n; i++)
		if(flag[i]){
			sum = s[i];
			flag[i] = 0;
			break;
		}
	for(int i = 1; i <= n; i++)
		if(flag[i])
			sum &= s[i];
	ans = max(ans, sum);
}
void dfs(int step){
	if(step == m){
		check();
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!flag[i]){
			flag[i] = 1;
			dfs(step + 1);
			flag[i] = 0;
		}
	}	
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	
	if(n <= 20){
		dfs(0);
		cout << ans;
		return 0;
	}
	
	if(n <= 2000){
		if(m == 1){
			for(int i = 1; i <= n; i++)
				ans = max(ans, s[i]);
			cout << ans;
			return 0;
		}
		if(m == n){
			ans = s[1];
			for(int i = 2; i <= n; i++)
				ans &= s[i];
			cout << ans;
			return 0;
		}
		if(m == 2){
			for(int i = 1; i < n; i++)
				for(int j = i + 1; j <= n; j++)
					ans = max(ans, s[i] & s[j]);
			cout << ans;
			return 0;
		}
		if(m == n - 1){
			int sum;
			for(int i = 1; i <= n; i++){
				if(i == n){
					sum = s[1];
					for(int j = 2; j < n; j++)
						sum &= s[j];
					ans = max(ans, sum);
				}
				sum = s[i + 1];
				for(int j = 1; j <= n; j++)
					if(j != i && j != i + 1)
						sum &= s[j];
				ans = max(ans, sum); 
			}
			return 0;
		}
	}
	else{
		f();
		if(x == 1){
			sort(s + 1, s + n + 1, cmp);
			cout << s[m];
			return 0;
		}
		if(x == 2){
			cout << n - m;
			return 0;
		}
		if(x == 3){
			for(int i = 1; i <= n; i++)
				c[s[i]]++;
			if(c[4] >= m)
				cout << 4;
			else if(c[3] >= m)
				cout << 3;
			else if(c[3] + c[2] >= m)
				cout << 2;
			else if(c[3] + c[1] >= m)
				cout << 1;
			else
				cout << 0;
			return 0;
		}
		else
			cout << 114514;
	}
    return 0;
}
//Trick||Treat!

