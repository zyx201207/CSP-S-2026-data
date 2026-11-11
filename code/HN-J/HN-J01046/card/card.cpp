#include <bits/stdc++.h>
using namespace std;
int n,m,card[500001],tong[300001],table[300002],hhh,tong2[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m); //nÕÅÅÆ£¬mÖÖÅÆ 
	for(int i=n;i>=1;i--){
		scanf("%d",&card[i]);
	}
	for(int i=1;i<=n;i++){
		memset(tong,0,sizeof(tong));
		memset(table,0,sizeof(table));
		long long hh=0;
		for(int i2=n-i+1;i2>=1;i2--){
			tong[card[i2]]++;
			if(tong[card[i2]]==2){
				for(int i3=n-i2;;i3--){
					if(table[i3]==card[i2]){
						table[i3]=0;
						tong[card[i2]]=1;
						break;
					}
					table[i3]=0;
				}
			}
			table[n-i2+1]=card[i2];
		}
		for(int i2=1;i2<=n;i2++){
			hh+=table[i2];
		}
		tong2[hh]++;
	}
	for(int i=1;i<=m;i++){
		cout<<tong2[i]<<' ';
	}
	return 0;
} 
