#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans;
int mx;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
       long long t=a[i];
       long long k=m;
       ans=0;
       for(int j=n;j>=1;j--){
          if(a[j]<=t&&k>=t-a[j]){
               ans++;
               k=k-t+a[j];
          }
       }
       mx=max(mx,ans); 
    }
    cout<<mx;
    return 0;
}
