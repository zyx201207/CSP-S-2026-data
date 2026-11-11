#include<bits/stdc++.h>
using namespace std;
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int cmp(int a,int b){
	return b<a;
}
int main(){
	long long n,m;
	cin >> n >>m;
	long long a[n];
	for(int i=0;i<n; i++ ){
		cin >> a[i];
	}	
	sort(a,a+n,cmp);
	int u=a[0];
	for(int i=1;i<m; i++ ){
		u=u&a[i];
	}
	cout << u;
	return 0;
}
