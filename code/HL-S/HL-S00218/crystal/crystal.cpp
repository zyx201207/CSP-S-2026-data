#include<bits/stdc++.h>
using namespace std;
	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",);
	int m,n;
	scanf("%11d%11", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%11d", &a[i]); 
	}
	sort(a+1, a+n-1);
	for(int i=2; i<=n; i++){
		m-=a[i]-a[i-1]*[i-1];
	}
	int ant=1;	
	
	return 0;
}
