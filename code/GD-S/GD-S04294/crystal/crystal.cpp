#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s;
long long a[1000005],f[10005][10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	k = m;
	s = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 2;i <= n;i++){
		for(int j = i-1;j > 0;j--){
		f[i][j] = f[i][j+1]+a[i]-a[j];
		if(f[i][j] <= m){
			if(i-j+1> s) s = i-j+1;
			}else break;
		}
	}
	cout << s;
	return 0;
}
