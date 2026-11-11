#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
int small(int mid){
	int len=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=mid){
			len=i;
		}
	}
	
		 for(int i=len;i>=1;i--){
	 	if(m>=(a[len]-a[i])){
	 	m-=(a[len]-a[i]);
	 	cnt++;
	 }
	 }
 return cnt;
}
   
int big(int mid){

	int len=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>mid){
			len=i;
			break;
		}
	}
		 for(int i=len;i>=1;i--){
	 	if(m>=(a[len]-a[i])){
	 	m-=(a[len]-a[i]);
	 	cnt++;
	 }
	 }
	 return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

   cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 sort(a+1,a+n+1);
	 int mid=(a[1]+a[n])/2;
	cout<<max(big(mid),small(mid));
	return 0;
} 
