#include<bits/stdc++.h>
using namespace std;
int a[500005],cards[500005],ies[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int clong=0;
		for(int j=i;j<=n;j++){
			for(int k=j;k<=clong;k++){
				if(cards[k]==a[j]){
					clong=k-1;
					break;
				}
			}
				clong++;
				cards[clong]=a[j];
		}
		for(int k=1;k<=m;k++){
			for(int j=1;j<=clong;j++){
				if(cards[j]==k){
				cout<<cards[j]<<" ";//ts
					ies[k]++;
					break;
				}
			}
		}
		clong=0;
		cout<<endl;//ts
	}
	for(int i=1;i<=m;i++){
		cout<<ies[i]<<" ";
	}
	return 0;
}
