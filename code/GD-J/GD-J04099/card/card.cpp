#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,k,a[N],ax[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int k = 1;k <= n;k++){
		for(int i = k;i <= n;i++){
			for(int j = k;j <= i;j++){
				if(a[i] == a[j]){
					for(int l = i;l <= j;l++) a[l]=0;
				}
			}
		}
	}
	return 0;
}
