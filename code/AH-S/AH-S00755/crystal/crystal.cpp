#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N],b[N];
ll ch[N];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
   ll n,m;
   cin>>n>>m;
   for(ll i=1;i<=n;i++){
	   cin>>a[i];
   }
   sort(a+1,a+1+n);
   for(ll i=2;i<=n;i++){
	   b[i]=a[i]-a[i-1];
   }
   for(ll i=2;i<=n;i++)ch[i]=ch[i-1]+b[i-1];
   ll sum=0,ans=0;
   ll id2=0;
   for(ll i=1;i<=n;i++){
	   sum+=(i-id2)*ch[i];
	   while(sum>m&&id2<=i){
		   sum-=b[id2];
		   id2++;
	   }
	   ans=max(ans,i-id2+1);
   }	   
   cout<<ans;
   return 0;
}
