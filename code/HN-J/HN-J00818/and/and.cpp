#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long n,m,ans=-10;  
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	 cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 } 
	 for(int i=1;i<=n-1;i++){
	 	for(int j=i+1;j<=n;j++){
	 		if((a[i]&a[j])>ans){
	 			ans=(a[i]&a[j]);
			 }
		 }
	 }
	 for(int i=1;i<=n-1;i++){
	 	for(int j=i;j<=n;j++){
	 		if((a[i]&a[j])==ans){
	 			a[i]=0;
	 			a[j]=0;
			 }
		 }
	 }
	 if((m-2)!=0){
	 
	 while((m-2)!=0){
	 	long long v=ans;
	 	for(int i=1;i<=n;i++){
	 		if((v&a[i])>ans){
	 			ans=(v&a[i]);
		 }
	 }
	 for(int i=1;i<=n;i++){
	 	if((v&a[i])==ans){
	 		a[i]=0;
	 		break;
		 }
	 }
	 m-=2;
	 }
	 
}
	 cout<<ans;
	return 0;
}
