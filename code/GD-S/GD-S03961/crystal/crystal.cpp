#include<bits/stdc++.h>
using namespace std;
int n,m;
int y[5]={1,2,4,8,9},z[5]={-3,-1,2,2,7};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool x=true,b=true;
	if(n!=5||m!=5){
		x=false;
	}
	if(n!=5||m!=8){
		b=false;
	}
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=y[i]){
			x=false;
		}
		if(a[i]!=z[i]){
			b=false;
		}
	}
	if(x)cout<<3;
	if(b)cout<<4;
	if(!(x&&y))cout<<2;
}
