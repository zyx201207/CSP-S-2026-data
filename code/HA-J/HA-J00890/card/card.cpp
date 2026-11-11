#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,j;
	cin>>n>>m;
	int a[n],k[m];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		k[i]=0;
	}
	for(int i=1;i<=n;i++){
		int b[n-i+1];
		for(j=i;j<n;j++){
			b[j-i+1]=a[j];
			for(int q=i;q<j;q++){
				if(b[q-i+1]==b[j-i+1]){
					for(int p=q;p<j;p++){
						b[p]=0;
					}
				}
			}
		}
		for(j=i;j<=n;j++){
			if(b[j]){
				k[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}
