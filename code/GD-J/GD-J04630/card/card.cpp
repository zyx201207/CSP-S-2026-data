#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int ls[500005];
		int xb =0;
		for(int l = i,r = n;l < r;l++,r--){
			bool isis = false;
			if(a[l] == a[r]){
				isis = true;
				for(int qp = i;qp <= n;qp++){
					ls[xb] = a[qp];
					if(qp == l){
						qp = r+1;
					}
					xb++;
				}
				break;
			}
			if(!isis){
				for(int qp = i;qp <= n;qp++){
					ls[xb] = a[qp];
					xb++;
				}
			}
		}
		for(int qq = 0;qq <= xb;qq++){
			ans[ls[qq]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
} 
