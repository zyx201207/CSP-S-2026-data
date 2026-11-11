#include<bits/stdc++.h>
using namespace std;
long long n,bl=0,bbl=0, dx=0,diff=0;
long long a[20005];
char c[20005];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	for(long long i = 0;i < n ;i++){
		dx=a[i];
		while(dx--){
			b[bl] = c[i];
			bl++;
		}
	}
	for(long long i = 0;i < bl;i++){
		if(b[i] != b[abs(bl-i-1)]){
			diff += a[i];
		}
	}
	diff/=2;
	printf("%lld",diff);
	return 0;
}
