#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],no[500005],isin[500005],k=1,last[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(isin,0,sizeof(isin));
		memset(no,0,sizeof(n));
		k=1;
		for(int j=i;j<=n;j++){
			if(isin[a[j]]==0){
				no[k]=a[j];
				isin[a[j]]=k;
				k++;
			}
			else {
				k=isin[a[j]]+1;
			}
		}
		for(int o=1;o<=k;o++){
			if(isin[no[o]]!=0){
			last[no[o]]++;
			isin[no[o]]=0;}
		}
	}
	for(int i=1;i<=m;i++){
		if(last[i]!=0){
			cout<<last[i]<<' ';
		}
	}
	return 0;
}
