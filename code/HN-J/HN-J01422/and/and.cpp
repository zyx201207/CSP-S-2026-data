#include<bits/stdc++.h>
using namespace std;
int n,m,id=0;
int a[10000000];
int cy(int x,int y,int o){
	if(o<=1){
		id=max(id,x);
		return x;
	}
    for(int i=y;i<n;i++){
    	int t=x&a[i];
    	cy(t,i+1,o-1);
	}
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m2;
    for(int i=0;i<n;i++){
    	cy(a[i],i+1,m);
	}
	cout<<id;
	return 0;
}
