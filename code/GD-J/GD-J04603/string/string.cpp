#include<bits/stdc++.h>
using namespace std;

long long n , a , b , s[10000100] , k , d , p;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a >> c;
		b += a;
		for(int j = k + 1;j <= b;j ++){
			s[j] = int(c);
			k = j;
		}
	}
	for(int i = 1;i <= b;i ++){
		d = b + 1 - i;
		if(s[i] != s[d]){
			s[d] = s[i];
			p ++;
		}
		if(i >= d){
			break;
		}
	}
	cout << p;
	return 0;
}
