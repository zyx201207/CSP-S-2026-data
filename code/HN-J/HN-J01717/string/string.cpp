#include <bits/stdc++.h>
using namespace std;
long long n,a[200009]={},sum=0;
char c[200009]={};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}	
	long long ans=0;
	int x=1,y=n;
	while(x <= y){
		if(a[x] == a[y]){
			if(c[x] != c[y]) ans += a[x];
			x++,y--;
		}else{
			if(a[x] > a[y]){
				if(c[y] != c[x]){
					ans += a[y];
				}
				a[x] -= a[y];
				y--;				
			}else if(a[x] < a[y]){
				if(c[y] != c[x]){
					ans += a[x];
				}
				a[y] -= a[x];
				x++;
			}
		}
	}
	cout << ans;
	return 0;
} 
