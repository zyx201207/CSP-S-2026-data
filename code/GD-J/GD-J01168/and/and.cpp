#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	num=a[1]&a[2];
	for(int i=3;i<=m;i++){
		num=num&a[i];
	}
	cout<<num;
	return 0;
}
