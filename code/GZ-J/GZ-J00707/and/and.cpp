//GZ-J00707 贵阳市第九中学 陈诗语
#include<bits/stdc++.h>
using namespace std;
int n,m,b,a[200002];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b=a[n];
	for(int i=n-1;i>n-m;i--){
		b=b&&a[i];
	}
	cout<<b;
	return 0;
}
