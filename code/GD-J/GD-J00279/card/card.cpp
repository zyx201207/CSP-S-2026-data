#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n;int m; cin >> n >> m;
	vector<int> card = {0};
	int end[m+1] = {0};
	for(long long i = 0;i < n;i++){
		int q = 0; cin >> q;
		card.push_back(q);
	}

	for(long long i = 1;i <= n;i++){
		vector<int> desk = {};
		int recorded[m+1] = {0};
		for(long long k = i;k <= n;k++){
			for(long long j = 0;j < desk.size();j++){
				if(desk[j] == card[k]){
					desk.erase(desk.begin()+j,desk.end());
					break;
				}
			}
			desk.push_back(card[k]);	
		}
		for(long long k = 0;k < desk.size();k++){
			if(recorded[desk[k]] == 0){
				end[desk[k]]++;
				recorded[desk[k]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++) cout << end[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
