#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans[268233483],l,s=1,z,sum,c;
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   scanf("%lld%lld",&n,&m);
   for(register int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ans[a[i]]++;
   }
   sort(a+1,a+n+1);
   c=a[1]-1;
   for(register int i=1;i<=n;i++){
        l=m;
        s=1;
        if(c==a[i])continue;
        c=a[i];
        while(l>0){
            z=a[i];
            if(z-a[s]>0)z=z-a[s];
            else break;
            if(l-z>=0){
                l=l-z;
                ans[a[i]]++;
            }else break;
            s++;
        }
        sum=max(sum,ans[a[i]]);
   }
   //for(int i=1;i<=n;i++)cout<<ans[a[i]]<<" ";
   printf("%lld",sum);
   return 0;
}
