#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k,x;
	sort(a+1,a+n+1,cmp);
	k=a[1];
	for(int i=2;i<=m;i++){
		x=k&a[i];
		k=x;
	}
	cout<<k;
	return 0;
}
