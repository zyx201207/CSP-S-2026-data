#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],b[300000],x=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	x=a[1];
	for(int i=2;i<=m;i++){
		x=x&a[i];
	}
	cout<<x;
	return 0;
}
