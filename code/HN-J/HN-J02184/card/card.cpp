#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int k,m,n,a[1000001],b[100001],h=0,c[1000001],r=0,g;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int k=1;k<=n;k++){
			for (int j=0;j<n-k+1;j++){
				b[j]=a[j];
				for (int l=0;l<j;l++){
					if (a[l]==b[l]){
						r=1;
					}
				}
				if (r==1){
					b[h]=a[j];
					h++;
				}
			}
			for (int j=0;j<m;j++){
				g=b[i];
				c[g]+=1;
			}
		}
	}
	for (int i=0;i<m;i++){
		cout<<c[g];
	}
	return 0;
}
