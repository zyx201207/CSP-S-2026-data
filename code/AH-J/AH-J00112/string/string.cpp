#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],l=0,c=0,d=0,q=0,h=0,p=1,k=1,s;
char z[200002],f,g;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>z[i];
        l+=a[i];
    }
    q=a[1];
    h=a[n];
    if(l%2==0){
        s=l/2;
    }
     else{
       s=(l-1)/2;
     }
    for(long long i=1;i<=s;i++){
        if(q>i){
            if(h>i){
                if(f!=g) c++;
            }
             else{
                k++;
                h+=a[k];
                g=z[k];
             }
        }
         else{
            p++;
            q+=a[p];
            f=z[p];
            if(h>i){
                if(f!=g) c++;
            }
             else{
                k++;
                h+=a[k];
                g=z[k];
                if(f!=g) c++;
             }
         }
    }
    printf("%lld",c);
    return 0;
}
