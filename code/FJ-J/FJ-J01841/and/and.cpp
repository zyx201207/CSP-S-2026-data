#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200000],b[200000],n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		b[i]=a[i]&a[i-1];
	}
	cout << b[m];
	return 0;
}
