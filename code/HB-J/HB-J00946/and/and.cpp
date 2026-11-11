#include<bits/stdc++.h>
using namespace std;
int ma=0;
int a[100001]={};
int xh(int x,int n){
	if(x>=n) return 0;
	for(int i=x;i<n;i++){
		int s=a[i] and a[i+1];
		if(s>ma) ma=s;
	}
	xh(x+1,n-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<ma+1;
	return 0;
}

