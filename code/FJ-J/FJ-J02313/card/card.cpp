#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		int k = i;
		while(k <= n){
			c[a[k]] ++;
			k = b[a[k]] + 1 ;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << c[i] << " ";
	}
	return 0;
}

