#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ink[500005],intk[500005],tip;
bool lan(int x){
	for(int i=1;i<=n;i++){
		if(ink[i]==x) return true;
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		tip=1;
		for(int j=i;j<=n;j++){
			ink[tip]=a[j];
			for(int k=1;k<tip;k++){
				if(ink[k]==ink[tip]){
					ink[k]=ink[tip];
					tip=k;
				}
			}
			tip++;
		}
		tip--;
		for(int j=1;j<=tip;j++) intk[ink[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<intk[i]<<" ";
	return 0;
}
