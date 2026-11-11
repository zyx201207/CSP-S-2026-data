#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[200050];
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a.start(),a.end(),cmp);
	int b=a[1];
	for(int i=2;i<=m;i++){
		b=b&a[i];
	} 
	cout<<b;
	return 0;
}
