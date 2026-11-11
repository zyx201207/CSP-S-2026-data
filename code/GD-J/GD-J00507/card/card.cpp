#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,poi;
	int table[500005]={};
	int hand[500005]={};
	int cnt[300005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>hand[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(hand[j]==table[k]){
					int table[500005]={};
					poi=1;
					break;
				}
			}
			table[poi]=hand[j];
			poi++;
		}
		for(int j=1;j<=n;j++){
			cnt[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
