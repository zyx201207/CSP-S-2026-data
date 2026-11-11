#include<bits/stdc++.h>
using namespace std;
int n , a , l;
char c;
string s , t;
long long ans , r;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d %c" , &a , &c);
		for(int j = 1; j <= a; ++j){
			s += c;
			++r;	
		}
	}
	--r;
	while(l <= r){
		if(s[l] != s[r]) ++ans;
		++l;
		--r;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

