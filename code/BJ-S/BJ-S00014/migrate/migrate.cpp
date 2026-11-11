#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[1000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
   cin>>c>>t;
   while(t--){
       for(long long j=0;j<n;j++)a[j]=0;
       cin>>n>>d;long long l1,l2,l3,l4,ans=0;
       for(long long i=0;i<n;i++)cin>>a[i];
       
       for(long long i=0;a[i]+d<=a[n-1];i++){
           l4=i+3;l3=l4-1;l2=l3-1;l1=l2-1;
           if((a[l4]-a[l3]<d)&&(a[l3]-a[l1]<=d)&&(a[l4]-a[l2]<=d)&&(a[l2]-a[l1]<d)&&a[l4]-a[l1]>d&&a[l4]-a[l1]%d!=0){
               ans++;
           }
           if(i>=4){
               long long h=i;
               while(a[h]-a[h-1]==d)h--;
                l4=h;l3=l4-1;l2=l3-1;l1=l2-1;
           if((a[l4]-a[l3]<d)&&(a[l3]-a[l1]<=d)&&(a[l4]-a[l2]<=d)&&(a[l2]-a[l1]<d)&&a[l4]-a[l1]>d&&a[l4]-a[l1]%d!=0){
               ans++;
           }
           }

       }
       cout<<"\n"<<ans;
   }
    
    return 0;
}