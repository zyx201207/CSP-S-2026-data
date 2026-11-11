#include<bits/stdc++.h>
using namespace std;
int a[10000006];
int nw[1000006];
int nwn = 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n;i++){
		for(int j = i; j <= n; j++){
			for(int k = 1; k <= nwn;k++){
				if(nw[k] == a[j]){
					for(int tmp = k; k <= nwn; k++){
						nw[k] = 0;
					}
				}else {
					nwn++;
					nw[nwn] = a[k];
				}
			}
		}
		for(int tmm = 1; tmm <= nwn; tmm++){
			if(nw[tmm] == i) cout << i << " ";
		}
		
	}
}
