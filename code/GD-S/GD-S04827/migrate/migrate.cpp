#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,c,a[20000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> x >> y;
	while(y--){
		cin >> n >> m;
		for(int i = 0;i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n - 3; i++){
			for(int j = 3; j < n - i; j++){
				long long d = a[j] - a[i];
				if(d > m && d % m != 0 && d / m + 1 >= j - 1 && m*(j - 1) > d){
					c++;
				}
			}
		}
		cout << c << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
