//GZ-S00377 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005][5005];
int c[5005][5005];
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin >> C >> T;
	while(T--){
		int n,d,sum=0;
		cin >> n >> d;
		for(int i =1;i <= n;i++){
			for(int j =1;j <= n;j++){
				b[i][j] = INT_MAX;
			}
		}
		for(int i =1;i <= n;i++){
			cin >> a[i];
		}
		if(n <= 3){
			cout << 0 << "\n";
			continue;
		}
		for(int j = 1;j < n;j++){
			for(int i = j+1;i <= n;i++){
				if(a[i]-a[j] <= d){
					b[j][i] = 1;
					c[j][i] = 1;
					continue;
				}
				for(int h = j+1;h <= i-1;h++){
					if(a[i] - a[h] <= d&&b[j][h] + 1 < b[j][i]){
						//cout << b[j][h] + 1 << " ";
						c[j][i] = 1;
						b[j][i] = b[j][h]+1;
					}else if(a[i] - a[h] <= d&&b[j][h] + 1 == b[j][i]){
						//cout << b[j][h] + 1 << " ";
						c[j][i]++;
					}
				}
			}
			//cout << "\n";
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				//cout << c[i][j] << " ";
				if(c[i][j] == 2){
					sum++;
				}
			}
			//cout << "\n";
		}
		cout << sum << "\n";
	}
	return 0;
}
