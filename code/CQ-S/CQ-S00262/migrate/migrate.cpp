#include<bits/stdc++.h>
using namespace std;

long long c;
long long d;
long long n, m;
long long a[2000005];

long long nxt[2000005];

long long vis[2000005];
long long pre[2000005];

void init(){
	for(int i = 1; i <= n; i++){
		nxt[i] = 0;
		vis[i] = 0;
		pre[i] = 0;
	}
	
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c;
	
	long long t;
	cin >> t;
	while(t--){
		cin >> n >> d;
		
		a[n + 1] = 4e18;
		
		long long k = log2(n);
		long long x1x = 1;
		
		for(long long i = 1; i <= n; i++){
			cin >> a[i];
			
			while(x1x < i){
				if(a[i] - a[x1x] > d){
					nxt[x1x] = i - 1;
					x1x++;
				}else{
					break;
				}
			}
		}
		
		for(long long i = x1x; i <= n; i++){
			nxt[i] = n;
		}
		
		
//		if(n <= 300){
//			int ans1 = 0;
//
//			for(int i = 1; i <= n; i++){
//				for(int j = 1; j <= n; j++){
//					vis[j] = 0;
//					pre[j] = 0;
//				}
//				
//				pre[i] = 0;
//				vis[i] = 1;
//				
//				for(int j = i + 1; j <= n; j++){
//					int ju = -1;
//					
//					for(int k = i; k < j; k++){
//						if(nxt[k] > j){
//							if(ju == -1){
//								ju = pre[k];
//							}else if(ju != pre[k]){
//								break;
//							}
//							
//							vis[j] += vis[k];
//						}
//					}
//					
//					if(vis[j] == 2){
//						ans1++;
//					}
//				}
//			}
//			
//			cout << ans1 << "\n";
//			
//			continue;
//		}
//		
		for(long long i = 1; i < n; i++){
			if(a[i + 1] - a[i] <= d && a[i + 2] - a[i] > d){
				vis[i] = 1;
			}
		}
		
		for(long long i = 1; i <= n; i++){
			pre[i] = pre[i - 1] + vis[i];
		}
		
		long long ans1 = 0;
		
		for(long long i = 1; i <= n; i++){
			long long l = i;
			long long r = n;
			
			while(l < r){
				long long mid = (l + r + 1) / 2;
				long long len = mid - i + 1;
				
				if(pre[mid] >= len - 1){
					l = mid;
				}else{
					r = mid - 1;
				}
			}
			
			
			long long x1x = nxt[l];
			
			if(x1x == l){
				continue;
			}
			
			
			long long ln = x1x - l;
			
			if(ln != 2){
				continue;
			}
			
			if(a[x1x + 1] - a[x1x] > d){
				continue;
			}
			
			long long ll = x1x + 1;
			long long rr = n;
			
			while(ll < rr){
				long long mid = (ll + rr + 1) / 2;
				long long len = mid - x1x;
				
				if(pre[mid] >= len - 1){
					ll = mid;
				}else{
					rr = mid - 1;
				}
			}
			
			ans1 += ll - x1x;
			
			if(a[x1x + 1] - a[x1x] > d){
				continue;
			}
			
			long long x2x = nxt[x1x];
			
			ans1 += x2x - ll;
		}
		
		cout << ans1 << "\n";
	}	
	
	return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
