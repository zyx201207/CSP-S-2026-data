#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],b[10000000],c[10000000],d=-1;
bool c(int x,int y){
	return x>y;
} 
int main(){
	freopen("and.in","r",stin);
	freopen("and.out","w",stout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n-i;j++){
			if(d<a[i]^a[j])d=a[i]^a[j];
		}
	}
	cout<<d;
	return 0; 
} 
