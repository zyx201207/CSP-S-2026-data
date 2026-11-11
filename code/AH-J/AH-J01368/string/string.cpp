#include<bits/stdc++.h>
using namespace std;
int n,d;
long long a[200005],sum,ans,road;
char s,a1[200005];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
    scanf("%d",&d);
    cin>>s;
    ans+=d;
    a[i]=d;
    a1[i]=s;
   }
   long long k=ans/2;
   if(ans%2==1){
    k--;
   }
   long long tail=n,head=1;
   while(road<k){
        if(a1[head]!=a1[tail]){
            if(a[tail]>a[head]){
                a[tail]=a[tail]-a[head];
                head++;
                sum+=a[head];
                road+=a[head];
            }else if(a[tail]==a[head]){
                tail--;
                head++;
                sum+=a[tail];
                road+=a[tail];
            }else{
                tail--;
                a[head]=a[head]-a[tail];
                sum+=a[tail];
                road+=a[tail];
            }
        }else{
            if(a[tail]>a[head]){
                a[tail]=a[tail]-a[head];
                head++;
                road+=a[head];
            }else if(a[tail]==a[head]){
                tail--;
                head++;
                road+=a[tail];
            }else{
                tail--;
                a[head]=a[head]-a[tail];
                road+=a[tail];
            }

        }
   }
 cout<<sum;
   return 0;
}
