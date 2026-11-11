#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
    int n,m;
    int a[500010];
    int as = -10;
    int qw = 0;
    int zx[500010];
    cin >> n >> m;
    for(int i = 0;i < n;i++){
       cin >> a[i];
    }
	for(int i = 0;i < n;i++){
		qw = 0;
		zx[i]++;
		for(int j = 0;i < n;i++){
			if(a[i] > a[j]){
				if(qw <= m){
					qw += (a[i]-a[j]);
					zx[i]++;
				}
			}
		}
	}
	for(int i = 0;i <= n;i++){
		as = max(zx[i],zx[i-1]);
	}
	cout << as;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
