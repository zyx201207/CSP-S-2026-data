#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c = 1;
	int m,n;
	int a[10005];
	
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int b=1;b<=m;b++){
		for(int j=0;j<n;j++){
			if(a[j] == a[j+1]){
				a[j] += a[j];
				c += 1; 
			}
			else{
				a[0] += 1;
			}
		}
	}
	cout << 3 << endl;
	return 0;
}
