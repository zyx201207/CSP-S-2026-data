#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int k,r,w,l,t;
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(a[i]<=a[i+1]&&a[i+1]<=a[i+2]){
		k=a[i+2];
		r=a[i+1];
		w=a[i];
		l=k-w;
		t=k-r;
		if(l+t==m){
			sum=i+2;
		
		}
		
	}}
	for(int j=1;j<=m;j++){
		if(a[i+2]==a[i++]){
			sum=sum+1;
			break;
			
		}
	}
	
}
cout<<sum;
return 0;
}
