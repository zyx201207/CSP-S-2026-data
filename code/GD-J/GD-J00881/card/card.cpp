#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(card.in,"stdin","r");
	freopen(card.out,"stdout","w");
	int n,m;
	cin>>n>>m;
	int a[50005];
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int num[30005];
	for(int p = 1;p<=n;p++){
		vector<int> card;
		int times[30005];
		int site[30005];
		for(int i = 1;i<=m;i++){
			site[i] = 0;
			times[i] = 0;
		}//Çå¿Õ 
		card.push_back(0);
		for(int i = p;i<=n;i++){
			card.push_back(a[i]);
			times[a[i]]++;
		}//ÅÆ¶Ñ 
		for(int i = 1;i<card.size();i++){
			if(site[card[i]] == 0){
				site[card[i]] = i;
			}
			else{
				for(int j = site[card[i]];j<=i-1;j++){
					times[card[j]]--;
				}
				site[card[i]] == i;
			}
		}//Í³¼Æ 
		for(int i = 1;i<=m;i++){
			num[i]+=times[i];
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
} 
