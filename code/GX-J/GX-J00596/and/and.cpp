#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m,ans = -1;
	cin >> n >> m;
	if(m == 1){
		for(int i = 1;i <= n;i++){
			int a;
			cin >> a;
			ans = max(ans,a);
		}
		cout << ans;
		return 0;
	}
	else if(m == 2){
		int a[200005];
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i < n;i++){
			for(int j = i;j <= n;j++){
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}
