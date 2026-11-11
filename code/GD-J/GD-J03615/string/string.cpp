#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
struct Node{
	int a;
	char c;
};
Node a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int L=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		L+=a[i].a;
	} 
	int ans=0;
 	int l=1,r=n;
 	while(l<r){
 		if(a[l].c!=a[r].c){
 			ans+=min(a[l].a,a[r].a);
 			//cout<<l<<' '<<r<<' '<<min(a[l].a,a[r].a)<<endl; 
			 
		 }
		 
		  if(a[l].a<a[r].a){
		  	a[r].a-=a[l].a;
			 	l++;
			 	
			 } else if(a[l].a>a[r].a){
			 	a[l].a-=a[r].a;
			 	r--;
			 	
			 }else{
			 	a[l].a=a[r].a=0;
			 	l++,r--;
			 	
			 }
	 } 
	 cout<<ans;
	
	return 0;
} 
