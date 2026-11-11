#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[500005],k=1;
		for(int j=i;j<=n;j++){
			b[k]=a[j];
			k++;
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(b[j]==b[k]&&j!=k){
					for(int l=j;l<=k-1;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int j=1;j<=n-i+1;j++){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}

