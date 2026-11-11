#include<bits/stdc++.h>
using namespace std;

int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	int ans = 0;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
		for(int j=0; j<m; j++){
			ans = max(a[i] and a[i+1],a[i+2] and a[i+3]);
		}
	}
	cout << ans ;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
