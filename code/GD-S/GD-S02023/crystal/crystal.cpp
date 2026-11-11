#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0;
	cin >> n;
	cin >> m;
	int a[n+2];
	for(int i = 1;i<=n;i++){
		cin >> a[i]; 
	}
	
	int c=m;
	a[0]=0; 
	for(int i = 1;i <= m;i++){
		for(int j= 1;j<=m;j++){
			if(a[i] != a[i-1]){
				a[i]++;
				c--;	
				
			}
			if(c==0) break;
		}
		
	}
	
	
	for(int i = 1;i<=n;i++){
		if(a[i]==a[i-1]){
			s++;
		}
	}
	cout << s;
	return 0;
} 
