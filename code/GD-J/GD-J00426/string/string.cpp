#include <bits/stdc++.h> 
#define ll long long
using namespace std;
ll n,m,x,sum;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i = 1;i <= n;i ++){
		scanf("%lld",&x);
		m += x;
		getline(cin,s1);
		for(ll j = 1;j <= x;j ++){
			s = s + s1[1];
			s2 = s1[1] + s2;
		}
	}for(ll i = 0;i < m;i ++){
		if(s[i] != s2[i]){
			sum ++;
		}
	}printf("%lld",sum / 2);
	return 0;
}
/*
3
2 a
2 b
1 c
2

2
2 a
3 a
0

6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
48
*/
