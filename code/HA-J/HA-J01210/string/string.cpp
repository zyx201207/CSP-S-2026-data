# include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long int b[N][N];
struct P{
	int sz;
	char zm;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n, sum = 0, ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].sz >> a[i].zm;
		for(int j = 1;j <= a[i].sz;j++){
			b[i][j] = a[i].zm;
		}
		sum += a[i].sz;
	}
	if(sum%2){//1
		for(long long int i = 1, j = sum;i <= sum/2, j > sum/2+1;i++, j--){
			for(long long int x = 1, y = sum;x <= sum/2, y > sum/2+1;x++, y--){
				if(!(b[i][j] == b[x][y])){
					ans++;
				}
			}
		}
	}
	else{
		for(long long int i = 1, j = sum;i <= sum/2, j >= sum/2+1;i++, j--){
			if(!(a[i].zm == a[j].zm)){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
