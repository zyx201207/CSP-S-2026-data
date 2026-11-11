#include <bits/stdc++.h>
using namespace std;
int cnt[300002] = {0};
int card[500002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> card[i];
	}
	for(int i = 1;i <= n;i++){
		int fg[300002] = {0};
		for(int j = i;j <= n;j++){
			if(fg[card[j]] == 1){
				int jj = j - 1;
				while(card[j] != card[jj]){
					fg[card[jj]] = 0;
					jj--;
				}
			}else fg[card[j]] = 1;
		}
		for(int j = 1;j <= m;j++){
			if(fg[j] == 1)cnt[j]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
