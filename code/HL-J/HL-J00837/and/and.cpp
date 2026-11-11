#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int cmp(int x,int y){
	return x >y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	for(int i = 1;i<m;i++){
		a[0]  = a[0] & a[i];
	}
	cout << a[0];
	return 0;
}