#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char c;
string a,b;
int main(){
    freopen("string.in",stdin);
	freopen("string.out",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> m >> c;
		ans += m;
		for(int j = m;j>=0;j--){
			a+=c;
		}
	}
	for(int i = ans;i >= 0;i--){
		b += a[i];
	}
	if(a != b){
		cout << ans/2;
	}
	return 0;
} 
