#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,mx=0,cmn=1e9,mn1=1e9;
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout << a[m];
	return 0;
}
