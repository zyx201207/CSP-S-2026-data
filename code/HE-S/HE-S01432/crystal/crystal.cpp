#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[100001],c=0,b[100001]={0},d=0,e; 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j]-a[i]<m){
				e==a[j]-a[i];
				m=m-e;
				a[i]==a[j];
			}
			if(a[i]==a[j]){
				c++;
				b[i]=c;
			} 
			if(d<=b[i]){
				d=b[i];
			}
		} 
	}
	cout<<d-n+3;
	return 0;
} 
