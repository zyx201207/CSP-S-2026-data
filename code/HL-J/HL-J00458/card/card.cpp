#include <bits/stdc++.h>
using namespace std;
int n,m;
int mmm;
int a[500005],b[500005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int nw = 1,sum = 0;
	for(int i = 1;i<=n;i++){
		nw = 1;
		sum = 0;
		for(int j = i;j<=n;j++){
			b[nw] = a[j];
			for(int k = nw - 1;k>0;k--){
				if(b[k] == b[nw]){
					for(int l = k;l < nw;l++){
						b[l] = 0;
					}
					b[k] = b[nw];
					b[nw] = 0;
					nw = k;
				}
			}
			nw++;
		}
		for(int f = i;f <= nw;f++){
			c[b[f]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout << c[i] + 1 << " ";
	}
	return 0;
}
