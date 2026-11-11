#include<bits/stdc++.h>
using namespace std;
int a[999999];
int b[999999];
int c[999999];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			b[a[j]] += 1;
			if(b[a[j]] == 2){
				int r = j - 1;
				while(a[r] != a[j]&&r > 0){
					b[a[r]] = 0;
					r -= 1;
				}
				b[a[r]] = 1;
			}
			
		}
		for(int k =1;k <= m;k++){
			if(b[k]>0){
				c[k] += 1;
				b[k] = 0;
			}
			b[k] = 0;
		}
	}
	for(int o =1;o <= m;o++){
		cout << c[o] << ' ';
	}
	return 0;
}
