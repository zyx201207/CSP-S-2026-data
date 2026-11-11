#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i]=a[i];
		}
		for(int j=i;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(b[k]==0)continue;
				if(b[k]==b[j]){
					for(int l=k;l<=j-1;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]==0)continue;
			if(b[j]<=m){
				t[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
