#include <bits/stdc++.h>
#include <algorithm>
using  namespace  std;
int  T(int  x,int  y){
	int  x1[100],y1[100],x2=0,y2=0,z[100],z2=1,z3=0;
	while(x){
		x1[x2]=x%2;
		x/=2;
		x2++;
	}
	while(y){
		y1[y2]=y%2;
		y/=2;
		y2++;
	}
	int  l=min(x2,y2);
	for(int  i=0;i<l;i++){
		if(x1[i]==y1[i]){
			z[i]=1;
		}else{
			z[i]=0;
		}
	}
	for(int  i=0;i<l;i++){
		z3+=z2*z[i];
		z2*=2;
	}
	return  z3;
}
int  main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int  n,m;
	cin>>n>>m;
	int  arr[n];
	for(int  i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int  ans=arr[n-1];
	for(int  i=2;i<=m;i++){
		ans=T(ans,arr[n-i]);
	} 
	cout<<ans;
	return  0;
} 
