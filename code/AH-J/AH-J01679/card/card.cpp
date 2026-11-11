#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int xb=i;
		for(int j=i;j<=n;j++){
			int l=0;
			for(int k=xb-1;k>=1;k--){
				if(b[k]==a[i]){
					xb=k;
					l=1;
				}
			}
			if(l==0){
				b[xb]=a[i];
			}
		}
		for(int j=i;j<=n;j++){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
