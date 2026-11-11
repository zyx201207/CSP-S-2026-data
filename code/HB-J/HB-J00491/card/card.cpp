#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int fi[500005],cou[500005],card[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r=1;
		for(int j=i;j<=n;j++){
			if(fi[a[j]]!=0){
				r=fi[a[j]];
				card[r++]=a[j];
			}else{
				fi[a[j]]=r;
				card[r++]=a[j];
			}
		}
		for(int j=1;j<r;j++){
			if(card[j])cou[card[j]]++;
		}
		memset(fi,0,sizeof(fi));
		memset(card,0,sizeof(card));
	}
	for(int i=1;i<=m;i++){
		cout<<cou[i]<<" ";
	}
	return 0;
}
