#include<bits/stdc++.h>
using namespace std;

char ch[20000000000000000000];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, len = 0, ans = 0;
	cin>>n;
	for(long long i = 1; i <= n; i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j = 1; j <= a; j++){
			ch[++len] = c;
		}
	}
	for(long long i = 1; i <= len/2; i++){
		if(ch[i] != ch[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
