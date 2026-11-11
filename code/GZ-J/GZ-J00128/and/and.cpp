//GZ-J00128 遵义市第十二中学 戴沉鑫 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, c = 0, ans = 0;
	int a[20005], pre[20005];
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n - m; i++){
		for(int j = i; j <= m ;j++){
			c |= a[j];
			ans = max(ans, c);	
		}
	}
	cout << c;
	fclose(stdin);
	fclose(stdout);
}

