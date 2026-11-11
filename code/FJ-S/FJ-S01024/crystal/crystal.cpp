#include<bits/stdc++.h>
using namespace std;
int n,m,ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[10005];
	int b[10005][10005];
	int c[10005][10005];
	int d[10005];	
	cin >> n >> m; 
	

	for(int i = 1;i<= n;i++){
		cin >> a[i];
	}
	
	for(int i = 1 ;i<= n;i++){
		for(int j = 1;j<= n;j++){
			if(a[j] -= a[i] < m) b[i][j] = a[j] -= a[i];
			else b[i][j] = 0;
			c[i][j] = a[i] += b[i][j];
		}
	}

	for(int i = 1;i<= n;i++){
		
		for(int j= 1;j<= n;j++){
			for(int k = 1;k<= n;k++){
				
					if(c[i][j] == c[j][k]) d[i]++;
			}
		}
		
	}
	
	sort(d,d+n);
	
	for(int i = 1 ;i<= n;i++){
		if(a[i] <= 0) {
			cout<<d[n]+1;
			return 0;
		}else{
			 
	cout<< d[n] -2;
		}
	}
		
	return 0;
	// 5 8 -3 -1 2 2 7
} 
