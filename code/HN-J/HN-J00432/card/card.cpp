#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
int vis[100005] = {};
set<int> p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				if(a[k] == a[j]){
					for(int y = j;y <= i - 1;y++){
						a[y] = 0;
					}
				}
			}
		}
		for(int j = 1;j <= n;j++){
			vis[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << vis[i] << " ";
	}
} 
