#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	if(m == 1){
		int ma = 0;
		for(int i = 1; i <= n; i++){
			ma = max(ma,a[i]);
		}
		printf("%d",ma);
		return 0;
	}
	if(m == 2){
		int ma = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(i != j){
					ma = max(ma,a[i] & a[j]);
				}
			}
		}
		printf("%d",ma);
		return 0;
	}
	return 0;
}
