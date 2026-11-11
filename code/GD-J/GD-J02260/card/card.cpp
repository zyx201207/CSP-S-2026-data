#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[500005];
int tong[500005];
int shu[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int k = 1;k <= m;k++){
			tong[k] = 0;
		}
		for(int j = i;j <= n;j++){
			if(tong[a[j]]){
				int flag = 0;
				for(int k = i;k <= j;k++){
					if(a[k] == a[j]){
						flag = 1;
					}
					if(flag){
						tong[a[k]] = 0;
					}
				}
				tong[a[j]] = 1;
			}else{
				tong[a[j]] = 1;
			}
		}
		for(int j = 1;j <= m;j++){
			if(tong[j]){
				shu[j]++;
			}
		}
	}
	for(int j = 1;j <= m;j++){
		cout << shu[j] << " ";
	}
	return 0;
} 
