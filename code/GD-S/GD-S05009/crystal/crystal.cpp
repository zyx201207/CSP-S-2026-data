#include<bits/stdc++.h>
using namespace std;
int n,m,b,ans;
vector<long long>a,aa,aaa;
auto check(int i, vector<long long>a,vector<long long>aaa){
           int l=1,r=i,mid;
           while(l<r)
           {
           	mid=(r+l+1)>>1;
           	if(m<aaa[i]-aaa[mid])
           	l=mid+1;
           	else
           	r=mid-1;
		   }
		   if(m>=aaa[i]-aaa[l])
           return i-l+1;
           return i-l;
           
           
           
		 /*while(l<=i){
		 	if(m<aaa[i]-aaa[l])
			 l++; 
			 else
			 break;
		 }
         return i-l+1;*/




}
int main(){
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
 scanf("%d%d",&n,&m);

 a.resize(n+1);

 aa.resize(n+1);

 aaa.resize(n+1);
 
 for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]); 
        if(a[i]==a[1])
        b++;
        }
        if(b==n){
        printf("%d",n);
        return 0;}
        sort(a.begin()+1,a.end());
        for(int i=1;i<=n;i++){
        aaa[i]=a[i]-a[1];
          } 
        for(int i=1;i<=n;i++){
           ans=max(ans,check(i,a,aaa));
          }
          printf("%d",ans);
return 0;
}
