#include<bits/stdc++.h>
using namespace std;
int main{
	freopen(“string.in”,“r”,stdin);
	freopen(“string.out”,“w”,stdout);
	int n,ans = 0;
	cin>>n;
	int a[n+5],c[n+5],q[n+5];
	for(int i = 1,i <= n,i++){
		cin >> a[i] >> c[i];
		for(int j = 1,j <= n,j++){	
			
	}
	for(int x = 1,x <= n,x++){		
		if(q[x]==q[n-x]){
			continue;
		else{
			ans++;
		}		
	}
	cout << ans;
	return 0;
}	