#include<bits/stdc++.h>
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
			b[j]=a[j];
			for(int k=i;k<j;k++){
				if(b[k]==b[j]){
					for(int l=k+1;l<=n;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			c[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[m]<<" ";
	}
	return 0;
}
