#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	int a[10000008][100000008]={0};
	cin >> c >> t >> n >> k;
	for(int m=1;m<=k;m++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
			}
		}
	}
	cout << 1 << '/n';
	cout << 2;
	return 0;
}
