#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x, long long y){
	return (x>y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin>>n>>m;
	long long a[n], num=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	num=a[0];
	for (int i=1;i<m;i++){
		num=num&a[i];
	}
	cout<<num;
	return 0;
}
