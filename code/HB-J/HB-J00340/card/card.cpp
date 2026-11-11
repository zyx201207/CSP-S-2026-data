#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,i,j,t=0;
	cin >> n >> m;
	long long a[n],ans[n][n],cnt[m];
	for (i = 0;i<m;i++){
		cnt[i] = 0;
	}
	for (i = 0;i<n;i++){
		for (j = 0;j<n;j++){
			ans[i][j] = 0;
		}
	}
	for (i = 0;i<n;i++){
		cin >> a[i];
	}
	for (long long x = 0;x<n;x++){
		t = 0;
		for (i = x;i<n;i++){
			for (j = i+1;j<n;j++){
				if (a[j] == a[i]){
					i = j;
					t = j;
					break;
				}
			}
		}
		for (long long y = t;y<n;y++){
			ans[x][y] = a[y];
		}
	}
	for (long long z = 1;z<=m;z++){
		for (long long x = 0;x<n;x++){
			for (long long y = x;y<n;y++){
				if (ans[x][y] == z){
					cnt[z-1] += 1;
				}
			}
		}
	}
	for (long long x = 0;x<m;x++){
		cout << cnt[x] << ' ';
	}
	return 0;
}
