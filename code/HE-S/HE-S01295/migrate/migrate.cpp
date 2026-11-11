#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int b[10000005];
int u[10000005];
int main(){
	int n,m;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,k,num = 0;
	cin >> c >> k;
	int sum = 0,x = 0,mx = 0,d = 0;
	for(int j = 1; j <= k; j++){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 1; i < n; i++){
			b[i] = a[i] - a[i - 1];
		}
		sum = 0;
		x = 0;
		mx = 0;
		d = 0;
		for(int i = 1; i < n; i++){
			sum += b[i];
			if(sum > m){
				x++;
				u[i] = i - 1;
				sum = 0;
				i--;
				d++;
			}
		}
		for(int i = 1; i < d; i++){
			if(u[i] - u[i - 1] == 1){
				num++;
			}
		}
		cout << num << endl;
	}
return 0;
}
