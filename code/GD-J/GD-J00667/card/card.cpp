#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fileIO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
}

const int N = 1e6;
int cards[N];
int inn[N];
int vis[N];

int main(){
	//fileIO("card");
	fastIO();
	int m,n;
	cin >> m >> n;
	for (int i = 0;i<m;i++){
		cin >> inn[i];
	}
	cards[0] = inn[0];
	for (int k = 0;k<n;k++){
		for (int i = 1;i<m-k;i++){
			bool flag = false;
			for (int j = 0;j<i;j++){
				if (cards[j] == inn[i+k]){
					flag = true;
					for (int l = j;l<m-k;l++){
						cards[l] = 0;
					}
					
				}
				cards[j] = inn[i+k];
				break;
				
			}
			
			
			if (flag == false){
				cards[i] = inn[i+k];
			}
		}
		for (int i = 0;i<m;i++){
			if (cards[i]!=0){
				vis[cards[i]]++;
			}
		}
		
	}
	for (int i = 0;i<m;i++){
		if (vis[inn[i]]!= 0){
			cout << vis[inn[i]] << ' ';
			vis[inn[i]]= 0;
		}
		
	}
	return 0;
}
