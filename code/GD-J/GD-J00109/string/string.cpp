#include<bits/stdc++.h>
using namespace std;

struct alpha{
	int num;
	char c;
}s[200010];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	
	int len = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d%s", &s[i].num, &s[i].c);
		len = len + s[i].num;
	}
	
	long long ans = 0;
	int l = 1, r = n;
	while(l < r){
		int mi = min(s[l].num, s[r].num);
		s[l].num -= mi;
		s[r].num -= mi;
		if(s[l].c != s[r].c){
			ans += mi;
		}
		if(s[l].num == 0){
			l++;
		}
		if(s[r].num == 0){
			r--;
		}
	}
	
	printf("%lld", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
