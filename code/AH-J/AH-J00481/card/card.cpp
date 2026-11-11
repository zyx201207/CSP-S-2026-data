#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int zz=0;
		for(int j=i;j<n;j++){
			bool y=false;
			c[zz]=a[j];
			zz++;
			for(int l=0;l<=zz;l++){
				if(c[l]==a[j]){
					y=true;
				}
				if(y){
					c[l]=0;
					zz--;
				}
			}
			if(y){
				c[zz]=a[j];
				zz++;
			}
		}
		for(int l=0;l<zz;l++){
			b[c[l]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
