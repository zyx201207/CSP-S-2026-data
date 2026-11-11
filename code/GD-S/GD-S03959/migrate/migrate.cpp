#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int c, T;
int a[5005][5005];
ll b[5005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		memset(a, 0, sizeof(a));
		int n;
		ll d;
		cin >> n >> d;
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(b[j]-b[i]<=d) a[i][j] = 1;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
	            int cnt = 1, road = 9999;
				if(a[i][j] == 0){
                    for(int k = i+1; k < j; k++){
                    	if(a[i][i+k]!=0&&a[i+k][j]!=0){
                    		a[i][j] = a[i][i+k]+a[i+k][j];
						}
						if(road > a[i][j]&&a[i][j]!=0){
							road = a[i][j];
							cnt = 1;
						}
						else if(road == a[i][j]&a[i][j]!=0){
							cnt++;
						}
					}
					a[i][j] = road;
					if(cnt==2){
						ans++;
					} 
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
