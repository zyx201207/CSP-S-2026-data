#include<bits/stdc++.h>
using namespace std;
long long a[10000000005];
char c[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, h=0, s=0;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> c[i];
	}
	for(int i=1; i<=n; i++){
		h+=a[i];
	}
	for(int i=1; i<=h/2; i++){
		if(c[i]!=c[h-i+1]) s++;
	}
	cout << s;
	return 0;
}
