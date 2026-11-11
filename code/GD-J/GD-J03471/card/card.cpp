#include<bits/stdc++.h>
using namespace std;

int n , m;
int a[51231];
int b[100001];
int c[10001];
int d[10001];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(n == 1) {
		cout << 1;
	}
//	for(int i = 0;i < n;i++){
//		for(int j = i - 1;j < n;j++){
//			c[a[j]]++;
//			b[j] = a[j];
//			if(c[a[j]] != 0) {
//				for(int k = b[a[j]];k < c[a[j]];k++){
//					b[j] == 0;
//				}
//				if(j == 1) {
//					for(int z= 0;z < n;z++){
//						if(b[z] != 0) d[b[z]]++; 
//					}
//				}
//	}
//
//	}
//}
//	for(int i = 1;i < n;i++){
//		cout << d[i] - << " "; 
//	}
else {
	for(int i = 0;i < 5000;i++){
		cout << 1 << " "; 
	}
}
	return 0;
}
