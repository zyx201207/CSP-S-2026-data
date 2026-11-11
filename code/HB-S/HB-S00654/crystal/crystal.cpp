#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   ll n,m,k;
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+1+n);
   ll l=1,r=n;
   while(l<=r){
	   ll mid=(l+r)/2,ans=0,f=0;
	   for(int i=1;i<=mid;i++){
		   ans+=a[mid]-a[i];
	   }
	   if(ans<=m) f=1;
	   else{
		   for(int i=mid+1;i<=n;i++){
			   ans+=(a[i]-a[i-1])*mid;
			   ans-=(a[i]-a[i-mid]);
			   if(ans<=m){
				   f=1;
				   break;
			   }
		   }
	   }
	   if(f==1){
		   k=mid;
		   l=mid+1;
	   }
	   else r=mid-1;
	   //cout<<l<<" "<<r<<"\n";
   }
   cout<<k;
}
