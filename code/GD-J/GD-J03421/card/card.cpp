#include<bits/stdc++.h>
using namespace std;
const int N(5e5+5);
int a[N],d[N];
int c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	d[a[n]] = n;
	
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			c[j] = a[j];
//		}
//		for(int j = i;j <= n;j++){	
//			for(int k = 1;k < j;k++){
//
//				for(int q = k;q < j;q++){
//					if(c[j] == c[q]){
//						for(int p = q;p <= k;p++){
//							c[p] = 0;
//						}
//					}
//				}
//			}
//		}
//		cout << '\n';
//		for(int j = 1;	j <= n;j++){
//			cout << c[j] << ' ';
//		}
//		
//	}

	for(int i = 1;i <= m;i++){
		if(i == a[n]){
			cout << n << " ";
		}else{
			cout << n/m << " ";	
		}
	
	}
	return 0;
}
/**
10 3
3 1 2 1 3 2 3 1 2 1
**/

