#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,l,a[1000000],ans[1000000],cmp=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		cmp=i;
		for(j=cmp;j<=n;j++){
			for(k=n;k>=cmp;k--){
				if((a[j]==a[k])&&(j!=k)){
					for(l=cmp;l<=j;l++){
						ans[a[l]]++;
					}
					cmp=k;
					k=n;
					j=cmp;
				}
			}
		}
		for(j=cmp;j<=n;j++)ans[a[j]]++;
	}
	for(i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
