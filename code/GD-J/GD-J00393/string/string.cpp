#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string S;
int n;
long long a;
char c, lc;
bool check(string S){
	int l = S.size();
	for(int i = 0;i < l;i++){
		if(S[i] != S[l - 1 - i]) return false;
	}
	return true;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%lld %c", &a, &c);
		if(a <= 9){
			for(int j = 1;j <= a;j++) S = S + c;
		}else S = S + c;
	}
	int len = S.size();
	if(check(S)){
		printf("0");
	}else{
		long long cnt = 0;
		while(!check(S)){
			S[len - cnt - 1] = S[cnt];
			cnt++;
		}
		if(a <= 9) printf("%lld", cnt);
		else printf("%lld", cnt * a);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
