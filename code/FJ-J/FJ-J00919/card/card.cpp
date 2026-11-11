#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],c[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(b[a[j]] == 0){
				b[a[j]]++;
				c[a[j]]++;
			}else{
				for(int k = 1;k <= i-1;k++){
					b[k]= 0;
				}
				c[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
	return 0;
}
