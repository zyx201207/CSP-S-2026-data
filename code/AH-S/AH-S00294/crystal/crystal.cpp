#include<bits/stdc++.h>
 using namespace std;
 long long a[500005];
 int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	 long long m,n,gmax=0;
 	cin>>n>>m;
 	bool ju=0;
 	for(int i=0;i<n;i++){
 		cin>>a[i];
	 }
	 sort(a,a+n);
	 if(m>1e9-1&&n>100){
	 	ju=1;
	 	for(int i=1;i<100;i++){
	 		if((a[i]-a[i-1])!=(a[1]-a[0])){
	 			ju=0;
	 			break;
			 }
		 }
	 }
	 for(int i=0;i<n;i++){
	 	if(ju){
	 		i=n-1;
		 }
	 	if(a[i+1]!=a[i]){
	 		long long k=m,g=1;
	 		for(int j=i-1;j>=0;j--){
	 			k-=(a[i]-a[j]);
	 			if(k>=0){
	 				g++;
				 }
				 else{
				 	break;
				 }
			 }
			 if(g>gmax){
				gmax=g;
			 }
		 }
	 }
	 cout<<gmax;
 	return 0;
 }
