#include<bits/stdc++.h>
using namespace std;
int sl[200010];
char zf[200010];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n,l=0,sum=0;cin>>n;int r=n-1;
   for(int i=0;i<n;i++) cin>>sl[i]>>zf[i];
   while(l<=r){
    if(sl[l]==sl[r]){
      if(zf[l]==zf[r]){
        l++;r--;continue;
      }
      else{
        sum+=sl[l];
           l++;r--;
        continue;
      }
    }
    else{
            if(zf[l]==zf[r]){
            sum+=abs(sl[l]-sl[r]);
            if(sl[l]>=sl[r]) sl[r-1]-=sl[l]- sl[r];
            else sl[l+1]-=sl[r]-sl[l];
            }
            else{
                sum+=max(sl[l],sl[r]);
                if(sl[l]>=sl[r]) sl[r-1]-=sl[l]-sl[r];
                else sl[l+1]-=sl[r]-sl[l];
            }
    }
    l++;r--;
   }
   cout<<sum;
return 0;
}
