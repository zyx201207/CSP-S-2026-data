#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],index[200010],an_max = INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= m;i++){
		index[i] = i;
	}
	for (int i = m;i >= 1;i--){//index±éÀú 
		int ans = a[index[1]];
		while (index[i] <= n){
			for (int j = 1;j <= m;j++){
				ans = ans and a[index[j]];
			}
			an_max = max(an_max,ans);
			index[i]++;
		}
	}
	cout << an_max;
	return 0;
}
