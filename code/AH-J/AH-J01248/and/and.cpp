#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	int cnt = 0;
	int ans = 0;
	int a[200010];
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1+cnt;i<=n-1;i++){
		for(int j = i+1;j<=n;j++){
			if(a[i] and a[j] >=ans){
				ans = a[i] and a[j];
			}
		}
		cnt++;
	}
	cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
