#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ac[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(ac,0,sizeof(ac));
		int k;
		for(int j=i;j<=n;j++){
			for(k=0;k<=j;k++){
				if(ac[k]==a[j]){
					for(int l=k;l<=j;l++){
						ac[l]=0;
					}
					break;
				}
			}
			ac[k]=a[j];
		}
		for(int j=1;j<=k;j++){
			b[ac[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
