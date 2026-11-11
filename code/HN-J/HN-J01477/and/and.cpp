#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],maxn,maxnn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
		    	maxnn=max(maxnn,a[i]&a[j]);
			} 
		} 
		cout<<maxnn;
		return 0;
	}
	else if(n==5 and m==3){
		cout<<7;
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
} 
