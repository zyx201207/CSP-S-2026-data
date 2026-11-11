#include <bits/stdc++.h>
using namespace std;
int n;
int a[200007];
char c[200007];
string s;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int len = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		len+=a[i];
		for(int j = 1; j <= a[i]; j++) s+=c[i];
	} 
	len/=2;
	long long ans=0;
	for(int i = 0; i < len; i++){
		if(c[i]!=c[len-i+1]) ans++;
	}
	cout << ans;
	
	return 0;
}
