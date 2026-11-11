#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],h,u;
int f(int o,int i,int v){
	if(i<m&&v>=n){
		return 0;
	}
	if(i==m){
		h=max(h,o);
		return 0;
	}
	for(int j=v+1;j<=n;j++){
		int k=o&a[j];
		f(k,i+1,j);
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		u=max(a[i],u);
	}
	if(m==1){
		cout<<u;
		return 0;
	}
	for(int i=1;i<=n;i++){
	    f(a[i],1,i);
	}
	cout<<h;
	return 0;
}
