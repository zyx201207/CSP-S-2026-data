#include<bits/stdc++.h>
using namespace std;
int a[50010];
int b[50010];
int main(){
	int n,m;
	cin>>n>>m;
	 for(int i=0;i<n;i++){
	 	cin>>a[i];
	 } 
	 sort(a,a+n);
	 for(int j=1;j<n;j++){
	 	b[j]=a[j]-a[j-1];
	 }
	 int s=0,max,t=1;
	 for(int j=1;j<=n;j++){
	 for(int i=j;i<=n;i++){
		s+=t*b[i];
		t++;
	 	if(s==m){ 
	 		max=t;
	 		t=0;
	 		s=0;
		 }
		 if(s>m){
		 	max=t-1;
		 	t=0;
		 	s=0;
		 }

	 }
	} 
	cout<<max<<endl;
} 
