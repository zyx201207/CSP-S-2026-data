#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n-i+1;k++){
				b[k]=a[j];
				for(int l=k;l>=1;l--){
					if(b[l]==b[k]){
						for(int h=l+1;h<=k;h++){
							b[h]=0;
						}
						k=l+1;
						break;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
