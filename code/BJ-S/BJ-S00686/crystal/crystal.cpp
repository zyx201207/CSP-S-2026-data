#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
bool check(int len){
    for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        if(len*a[j]-s[j]+s[i-1]<=m) return 1;
    }
    return 0;
}
signed main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   s[0]=0;
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+n+1);
   int x=a[1]-1;
   for(int i=1;i<=n;i++) a[i]-=x;
   for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
   int l=1,r=n,lst;
   while(l<r){
    int mid=(l+r)>>1;
    if(mid==lst) break;
    if(check(mid)) l=mid;
    else r=mid-1;
    lst=mid;
   }
   cout<<l;
   return 0;
}
