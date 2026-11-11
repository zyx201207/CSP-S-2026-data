#include <bits/stdc++.h>
using namespace std;

int n, m, card[500005], table[500005], last[300005];

bool same(int s){
	for(int i=0; i<n-1; i++){
		if(table[i]==0) break;
		if(table[i] == s) return 1;
	}
	return 0;
}

void swap(int x){
	for(int i=0; i<x; i++){
		table[i] = 0;
	}
	table[0] = table[x];
}

int main(){
	//freopen("card.in", "r", stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> card[i];
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			table[j-i] = card[j];
			if(same(card[j])){
				swap(j);
			}
		}
		for(int j=0; j<=n; j++){
			if(table[j] == 0) break;
			last[table[j]]++;
		}
	}
	for(int i=0; i<m; i++){
		cout << last[i] << " ";
	}
	return 0;
}
