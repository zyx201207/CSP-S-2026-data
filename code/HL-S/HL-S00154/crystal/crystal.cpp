#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],s[500010];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin >> n >> m;
	for (long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (long long i = 1; i <= n; i++){
		s[i] = s[i-1] + a[i];
	}
	for (long long i = n; i >= 1; i--){
		if (a[i]*(i-1) - s[i-1] <= m){
			cout << i;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
