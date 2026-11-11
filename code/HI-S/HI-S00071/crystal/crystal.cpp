#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],b[500500],ma=INT_MIN;
bool fdc=1;
int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0),cout.tie(0);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(i>2){
 			if(!(a[i]-a[i-1]==a[i-1]-a[i-2])) fdc=0;
		 }
	 }
 	sort(a+1,a+n+1);
 	if(fdc==1){
 		long long d=a[2]-a[1],mx=INT_MIN;
 		for(int i=1;i<=n;i++){
 			if(double(i)/2*(i-1)*d<=m){
 				mx=i;
			 }
			 else {
			 	break;
			 }
		 }
 		cout<<mx;
 		return 0;
	 }
	 for(int i=1;i<=n;i++){
	 	long long s=0;
	 	long long l=1,r=i,mid=(l+r)/2;
	 	while(l<r){
	 		for(int j=mid;j<i;j++){
	 			s+=(a[i]-a[j]);
				 if(s>m) break;
			 }
			 if(s>m) l=mid+1;
			 else if(s<m){
			 	if((i-mid+1)>ma) ma=(i-mid+1);
			 	r=mid;
			 } 
			 if(s==m){
				if((i-mid+1)>ma) ma=(i-mid+1);
				break;
			 } 
			 mid=(l+r)/2;
			 s=0;
		 }
	 }
	 cout<<ma;
 	return 0;
}
