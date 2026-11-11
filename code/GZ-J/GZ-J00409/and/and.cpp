//GZ-J00409 遵义市第四中学 魏云藩 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n = 0,m = 0,num1 = 0,num2 = 0,b = 0,ans = 0;
	cin >> n >> m;
	int a[n]={},t[100010]={};
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	for (int i = 0;i < n;i++){
		for (int j = i+1;j <= n;j++){
			if (ans < a[i] and a[j]){
				ans = a[i] and a[i];
			}
			b++;
		}
	}
	cout << ans;
	return 0;
}
