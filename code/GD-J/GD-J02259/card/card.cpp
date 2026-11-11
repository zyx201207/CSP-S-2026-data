#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		for(int i=1+k-1;i<=n;i++){
			b[i]=a[i];
			for(int j=1;j<i;j++){
				if(b[j]==a[i]){
					for(int l=j;l<=i-1;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			f[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << f[i] << " ";
	}
	return 0;
}
