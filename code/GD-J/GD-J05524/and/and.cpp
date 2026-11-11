#include<bits/stdc++.h>
using namespace std;
int x,y;
int a[200005];
int f(int t,int p){
	if(t<=1){
		return a[p];
	}
	int z=0;
	for(int i=p+1;i<x;i++){
		z=max(z,a[p]&f(t-1,i));
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>x>>y;
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	int j=0;
	for(int i=0;i<x-y;i++){
		j=max(j,f(y,i));
	}
	cout<<j;
} 
