#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	int a[1001],b[1001];
	int n=0,m=0,p;
	while(x!=0){
		a[n]=x%2;
		n++;
		x/=2;
	}
	while(y!=0){
		b[m]=y%2;
		m++;
		y/=2; 
	} 
	if(n<m){
		n=m;
	} 
	for(int i=n;i>=0;i--){
		if(a[i]==b[i]&&a[i]==1){
			p+=pow(2,i);
		}
	}
	return p;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	int a[100001]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int manx=0;
	for(int i=1;i<=n;i++){
		int x=a[i];
	    for(int j=i;j<=i+m;j++){
	    	x=cmp(x,a[j]);
		}
		if(maxn<x){
		 maxn=x;
	   }
	}
	cout<<maxn;
}
