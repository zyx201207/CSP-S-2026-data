#include <bits/stdc++.h>
using namespace std;
int n,m;
int q=0;
int a[500005],b[500005],c[500005],d[500005];
bool qw(int k){
	for(int j=1;j<=k-1;j++){
		if(a[j]==a[k]){
			q=j;
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=500005;j++){
			b[j]=0;
			d[j]=0;
		}
		for(int k=i;k<=n;k++){
			if(qw(k)){
				for(int j=q;j<=k-1;j++){
					b[j]=0;
				}
			}
			b[k]=a[k];
		}
		for(int l=1;l<=n-i+1;l++){
			if(d[b[l]]==0){
				c[b[l]]++;
				d[b[l]]==1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
 
