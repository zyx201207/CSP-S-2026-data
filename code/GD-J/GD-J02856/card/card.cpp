#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],b[5005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int i1=1;i1<=n;i1++) b[i]=a[i];
		for(int j1=1;j1<=n;j1++){
			for(int j=1;j<=m;j++){
				for(int k=j;k>=1;k--){
					if(b[k]==b[j]){
						for(int k1=j;k1>=1;k1--){
							b[k1]=1e9;
						}
					}
				}
			}
			for(int l=1;l<=m;l++){
				if(b[l]==i) cnt++;
			}
		}
		cout<<cnt;
		cnt=0;
	}
	return 0;
}
