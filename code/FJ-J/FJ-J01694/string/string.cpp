#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	long long ans = 0;
	scanf("%d",&n);
	long long aa = 0;
  	for(long long i=0;i<n;i++){
		long long a;
		char c;
		scanf("%d",&a);
		if(i == 0) aa = a;
		cin >> c;
		s[i] = c; 
	}
	for(long long i=0;i<n/2;i++){
		if(s[i] != s[n - i - 1]){
			ans++;
		}
	}
	cout << ans * aa;
	return 0; 
}
