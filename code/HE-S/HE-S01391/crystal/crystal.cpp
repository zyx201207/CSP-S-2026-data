#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c,he;
	int h;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	long long i=1;
	 while(ans<=m){
	 	if(a[i]<0){
	 	
	 		c=(0-a[i])*2; ans+=c;	a[i]=0-a[i];
		 }
		 else{ans+=a[i];
//		 cout<<ans<<"   ans";
		 }
		 
		 h=i;
		 if(h==n)break;
//		 ÕÒµ½±àºÅ 
		 i++;
	 }
	 if(ans>m){
	 	h--;
	 }
	 for(int k=1;k<=n;k++){
	 	if(a[k]==0){
	 		h--; 
		 }
	 }
//	 cout<<h<<"   h"<<endl;
	 long long chong=0;
	 for(int k=h;k<=n;k++){
	 	if(a[k]==a[h+1]){
	 		chong+=1;
//	 		cout<<chong<<endl;
		 }
	 }
	 long long ji=0,q;
	 for(int j=1;j<=h;j++){
	 	if(a[j]>=a[h+1]){q=a[h+1]+a[j];
		 }
		 else{q=a[h+1]-a[j];
		 }
	 	
//	 	cout<<q<<" yhg"<<endl;
	 	ji+=q;
	 	
	 }
//	 cout<<ji<<"   J";
	 if(ji<=m){
	 	cout<<h+chong;
	 }else{cout<<h;
	 }return 0; 
	 }
	
	
	
	
	
	
	
