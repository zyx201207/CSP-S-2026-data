#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[100000],l,sum,s,v,w;
int main(){
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   scanf("%d%d",&c,&t);
   for(register int h=1;h<=t;h++){
   scanf("%d%d",&n,&d);
   w=0;
   for(register int i=1;i<=n;i++)scanf("%d",&a[i]);
   for(int i=1;i<n;i++){
        if(s!=v)w=1;
    s=a[i]-a[i+1];
    v=s;
   }
   if(w==0){
        cout<<0<<"\n";
   return 0;
   }
   for(register int i=1;i<=n;i++){
        for(register int j=i+3;j<=n;j++){
            for(register int k=i+1;k<=j;k++){
                    if(a[k]-a[i]<=d&&a[j]-a[k]<=d)l++;
        }
        if(l==2)sum++;
        l=0;
   }
   }
   printf("%d\n",sum);
   }
   return 0;
}
