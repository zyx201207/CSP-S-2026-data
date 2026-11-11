#include<bits/stdc++.h>
using namespace std;
long long n,a,c=0;
char s[200005],s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 0;i<n;i++){
		cin >> a >> s1;
		long long len = strlen(s);
		for(long long j = 1;j<=a;j++){
			s[len] = s1;
		}
	}
	for(int i = 0;i<strlen(s);i++){
		if(s[i] != s[strlen(s) - i - 1]){
			c ++;
		}
	}
	cout << c;
	return 0;
}
