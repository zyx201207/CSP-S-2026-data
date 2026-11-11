#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int num;
    char x;
}a[200033];
int ans;
signed main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n;cin>>n;
   for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].x;
   }
   int l=0,r=0;
   for(int i=n;i>=n/2;i--){
        int bc,fr;
        bc=i,fr=n-i+1;
        if(fr>bc)break;
        l+=a[fr].num,r+=a[bc].num;
        if(a[bc].x!=a[fr].x){
            ans+=min(a[bc].num,a[fr].num);
            if(l!=r){
              ans+=abs(l-r);
            }
        }
   }
   cout<<ans;
   return 0;
}
