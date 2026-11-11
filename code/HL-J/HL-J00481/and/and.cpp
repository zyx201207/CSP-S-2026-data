#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",r,stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;

	return 0;
}
