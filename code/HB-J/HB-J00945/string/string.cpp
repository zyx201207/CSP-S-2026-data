#include <bits/stdc++.h>
using namespace std;
int n,m;
string a[505];
string k[1];
int z,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> m >> k[0];
		int j = m;
		while(j){
			a[z] = k[0];
			z ++;
			j --;
		}
	}
	z-=1;
	for(int i = 0;i <= z/2+z%2;i ++){
		if(a[i] != a[z-i]){
			ans ++;
			a[i] = a[z-i];
		}
	}
	cout << ans;
	return 0;
}
