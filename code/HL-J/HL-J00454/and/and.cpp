#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int s[100000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++){
		a[1]&=a[i];
	}
	cout<<a[1];
	return 0;
}
