#include<bits/stdc++.h>
using namespace std;
string s,c,sf;
long long n,a[200005],si=1,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(long long j = 1;j <= a[i];j++){
			s[si] = c[i];
			si++;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	if(n == 2){
		if(c[1] == c[2]){
			cout << 0;
			return 0;
		}
		if(a[1] >= a[2]){
			cout << a[2];
		}else{
			cout << a[1];
		}
		return 0;
	}
	if(si / 2 == 0){
		for(long long i = 1;i <= si/2;i++){
			if(s[i] != sf[i]) sum++;
		} 
	}else{
		for(long long i = 1;i <= (si+1)/2;i++){
			if(s[i] != sf[i] && i != (si+1)/2) sum++;
		}
	}
	cout << sum;
	return 0;
} 
