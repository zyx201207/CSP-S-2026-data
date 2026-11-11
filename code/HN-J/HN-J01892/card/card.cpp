#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n, m;
int a[MAXN];
int tong[300005];
int tong2[300005];
int desk[MAXN];
int index = 1;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
    	cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (tong2[a[j]] != 0){
				for (int l = tong2[a[j]] + 1; l <= n; l++){
					tong2[desk[l]] = 0;
					desk[l] = 0;					
				}
				index = tong2[a[j]];
				tong2[a[j]] = index;
				index++;
			}else{
				desk[index] = a[j];
				tong2[a[j]] = index;
				index++;
			}
			
		}
		for (int i = 1; i <= n; i++){
			tong[desk[i]]++;
		}
//		for (int i = 1; i <= n; i++){
//			cout << desk[i] << " ";
//		}
//		cout << endl;
		memset(tong2, 0, sizeof(tong2));
		memset(desk, 0, sizeof(desk));
		index = 1;
	}
	for (int i = 1; i <= m; i++){
		cout << tong[i] << " ";
	}
	return 0;
}


