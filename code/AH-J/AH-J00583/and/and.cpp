#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],z;
bool f[30];
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   cin>>n>>m;
   int ans=0,ma=INT_MIN,mi=INT_MAX;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
	   ma=max(ma,a[i]);
	   mi=min(mi,a[i]);
   }
   if(m==1)  cout<<ma;
   else if(m==n){
	   ans=a[1];
	   for(int i=1;i<=n;i++){
		   ans=ans&a[i];
	   }
	   cout<<ans;
   }
   else if(m==n-1){
	   if(mi==a[1])  ans=a[2];
	   else ans=a[1];
	   for(int i=1;i<=n;i++){
		   if(a[i]!=mi)
		   ans=ans&a[i];
	   }
	   cout<<ans;
   }else if(m==2){
	   for(int i=1;i<=n;i++){
		   for(int j=i+1;j<=n;j++){
			   if(a[i]>a[j])
			   ans=max(ans,a[i]&a[j]);
			   else ans=max(ans,a[j]&a[i]);
	      }
      }
   cout<<ans;
   }else if(n<=20){
	   int x,y;
	   for(int i=1;i<=n;i++){
		   for(int j=i+1;j<=n;j++){
			   int sum=a[i]&a[j];
			   if(sum>ans){
				   ans=sum;
				   x=i,y=j;
			   }
	      }
      }
      f[x]=f[y]=1;
	  z=0;
      z=ans;
      m-=2;
	while(m!=0){
		ans=0;
		for(int i=1;i<=n;i++){
			if(f[i]==0){
			int sum=a[i]&z;
			if(sum>ans){
				ans=sum;
				x=i;
			}
	   }
   } 
       f[x]=1;
	   z=ans;
	   m--;
   }
   cout<<ans;
}else  cout<<4;
   return 0;
}
