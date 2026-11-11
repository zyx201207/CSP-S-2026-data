#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
	   cin>>a[i]>>c[i];
   }
   int s1=1,s2=n;
   long long ans=0;
   while(s1!=s2){
	   if(a[s1]>a[s2]){
		   a[s1]-=a[s2];
		   if(c[s1]!=c[s2])
		   ans+=a[s2];
		   s2--;
	  }else if(a[s1]<a[s2]){
		  a[s2]-=a[s1];
		  if(c[s1]!=c[s2])
		  ans+=a[s1];
		  s1++;
	  }else{
		  if(c[s1]!=c[s2])
		  ans+=a[s1];
		  s1++;
		  s2--;
	  }
   }
   printf("%lld",ans);
   return 0;
}
