#include <bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m;
int a[N],b[N],z[N];//aÅÆ   z×ÀÃæ 
bool zuo(int n){
	for (int i=1;i<=n;i++){
		if (z[i]==n){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i,k=1;j<=n;j++){
			if (zuo(a[i])){
				z[k]=a[i];
				k++;
			}
			else {
				bool l=0;
				for (int s=1;s<=n;s++){
					if (l){
						z[s]=0;
						k=s;
					}
					if (z[s]==a[i]){
						l=1;
					}
				}
			}
		}
		for (int j=i;j<=n;j++){
			
		}
	}
} 
