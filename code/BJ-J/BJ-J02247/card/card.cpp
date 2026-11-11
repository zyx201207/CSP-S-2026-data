#include<bits/stdc++.h>
using namespace std;

int a[200050],n,m;
int gm[200050],sum[200050];
bool vis[200050];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	for(int i = 1;i <= n;i++){
		for(int k = 1;k <= m;k++)vis[k] = 0;
		int id = 1;
		for(int j = i;j <= n;j++){
			if(!vis[a[j]]){
				gm[id] = a[j];
				vis[a[j]] = 1;
				id++;
			}
			else {
				while(gm[id] == a[j]){
					id--;
					gm[id] = 0;
				}
				gm[id] = 0;
			}
		}
		for(int i = 1;i <= id;i++){
			sum[gm[i]]++;
//			cout << gm[i] << " ";
		}
//		cout << endl;
	}
	
	for(int i = 1;i <= m;i++){
		cout << sum[i] << " ";
	}
	
	return 0;
	
}
