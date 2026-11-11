#include<bits/stdc++.h>                                                          
using namespace std;
long long int n, m;
int ans;
const int N = 500005;
int a[N], b[N];//b[i] = q[i]
int f(){
	int s1 = 1, a1 = -9999;
	for(int i = 1; i <= n; i++){
		b[i] += a[i]; 
	}
	sort(b + 1, b + n - 1);
	for(int i = 1; i < n; i ++){
		if(a[i] = a[i-1]){
			s1 ++;
		}	
		else{
			a1 = max(a1, s1); 
		}
	}
	return a1;
}
void dfs(int s2, int s){
	if(m == s2){
		ans = max(ans, f());                                                                                           
		return ;
	}	
	for(int i = s; i <= n; i ++){
		a[i] ++;
		dfs(s2 + 1, s);
		a[i] --; 
	}

}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n - 1);
	dfs(0, 1);
	cout << ans + 3;
/*	for(int i = 1; i <= n; i++){
		if(a[1] > 0){
			while(true){
				if(a[i] < a[i + 1]){
					a[i] ++;
				}
				if(a[i] == a[i + 1]){
					break;
				}
			}
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
