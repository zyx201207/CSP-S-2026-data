#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[2005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<= n; i++){
		cin >> a[i];
	}
	if(n<=2000){
		int maxn = 0;
		
		for(int i=1; i<=m; i++){
			b[i] = i;
		}
		int delta = n-m;
		int ind = m;
		while(b[0]==0){
			int cur = a[b[1]];
			for(int i = 2; i<=m; i++){
				cur &= a[b[i]];
			}
			maxn = max(maxn, cur);
			
			b[m]++; 
			if(b[ind]>ind+delta){
				while(b[ind]>=ind+delta){
					ind--;
				}
				b[ind]++;
				for(int j = ind+1; j<=m; j++){
					b[j]=b[j-1]+1;
				}
				ind = m;
			}
		}
		cout << maxn;
	}
	
	
	
	return 0;
}
