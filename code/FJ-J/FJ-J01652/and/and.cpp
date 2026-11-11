#include <bits/stdc++.h>
using namespace std;
int a[200005];
int andm(int x,int z,int c){
	if(c==0)return x&a[z];
	return andm(a[x]&a[z],z+1,c-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxs=0;
	for(int i=1;i<=n-m+1;i++){
		maxs=max(maxs,andm(i,i+1,m));
	}
	cout<<maxs;
	return 0;
}