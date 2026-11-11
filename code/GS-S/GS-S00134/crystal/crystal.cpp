#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
long long x = 0;

int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	sort(a + 1,a + 1 + n);
	
	for(int i = n;i >= 1;i--){
		for(int j = 1;j <= i;j++){
			x += a[i] - a[j]; 
		}
		
		if(x > m){
			x = 0;
			continue;
		}else{
			cout << i;
			return 0;
		}
	}
	return 0;
} 
