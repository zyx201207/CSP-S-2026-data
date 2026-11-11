#include <bits/stdc++.h>
using namespace std;
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout); 
	int n , m;
	cin >> n >> m;
	long long a[20010];
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1 , cmp);
	string b[20010];
	for(int i = 1 ; i <= m ; i++){
		string x;
		while(a[i] != 0){
			x += to_string(a[i] % 2);
			a[i] /= 2;
		}
		b[i] = x;
		for(int j = 0 ; j < x.size() ; j++){
			b[i][j] = x[x.size() - j - 1];
		}
	}
	string ans = b[1];
	for(int i = 1 ; i <= m ; i += 2){
		int y = 0;
		for(int j = 0 ; j < b[i].size() ; j++){
			string q = ans , p = b[i + 1];
			if(q[j] == p[j]){
				ans[y] = '1';
				y++;
			}
			else{
				ans[y] = '0';
				y++;
			}
		}
	}
	int aaans = 0;
	for(int i = 0 ; i < ans.size() ; i++){
		if(ans[i] == '1'){
			aaans += pow(2 , ans.size() - 1 - i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout << aaans;
	return 0;
}
