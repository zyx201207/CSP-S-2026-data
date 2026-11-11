#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int c[500010];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			//±È½Ï 
			for(int k=1; k<=ans+1; k++){
				if(a[j] == c[k]){
					ans = k-1;
				}
			}
			ans++;
			c[ans] = a[j];
		}
		for(int j=1; j<=ans; j++){
			b[c[j]]++;
		}
		c[1] = 0;
		ans = 0;
	}
	for(int i=1; i<=m; i++){
		cout << b[i] << ' ';
	}
	return 0;
}
