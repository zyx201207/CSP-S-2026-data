#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int k=a[1];
		for(int i=2;i<=n;i++){
			k=k&a[i];
		}cout<<k;
	}else{
		sort(a+1,a+n+1,cmp);
		int k=a[1];
		for(int i=2;i<=m;i++){
			k=k&a[i];
		}cout<<k;
	}
	return 0;
}
