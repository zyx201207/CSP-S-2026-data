#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,round=1;
	cin>>n>>m;
	int a[500005];
	int cnt[300005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(round<=n){
		int card[500005]={};
		int card_size=0;
		for(int i=round;i<=n;i++){
			for(int j=0;j<card_size;j++){
				if(a[i]==card[j]){
					for(int k=j;k<card_size;k++){
						card[k]=0;
					}
				}
			}
			card[card_size]=a[i];
			card_size++;
		}
		for(int i=0;i<card_size;i++){
			cnt[card[i]]++;
		}
		round++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
