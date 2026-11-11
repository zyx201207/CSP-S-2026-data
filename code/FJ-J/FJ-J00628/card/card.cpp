#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// dp!!! 

//模拟先(钓鱼?!)

// O(n^2) - 48pts
int a[1000005]; // O(n) or O(n \log g)
int b[1000005], pm[1000005], idx = 0; // 空间换时间 
//pair<int, int> kp[1000005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false); // 数据较大，保险 (卡常ovo)
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	
	for(int i = 0; i < n; i ++ ){
//		memset(kp, 0, sizeof kp);
		idx = 0;
		
		for(int j = i; j < n; j ++ ){
			for(int k = idx - 1; k >= 0; k -- ){
				if(pm[k] == a[j]){
					idx = k;
					break;
				}
			}
			
			
//			if(kp[a[j]].first == 1) idx = kp[a[j]].second;
//			
//			pm[idx ++ ] = a[j];
//			kp[a[j]] = {1, idx - 1};
		}
		
		for(int i = 0; i < idx; i ++ ) b[pm[i]] ++;
	} // O(n ^ 3) 
	
	for(int i = 1; i <= m; i ++ ) cout << b[i] << " ";
	
	return 0;
} 
