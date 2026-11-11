#include <bits/stdc++.h>
using  namespace std;
long long n,m,a[10000000],b[100000],c[1000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for(long long i=0;i<n;i++){
         cin>>a[i];
         c[i]=0;
         b[i]=0;
    }
    for(long long i=0;i<n;i++){
        long long k=0;
        for(long long j=i;j<n;j++){
            for(long long z=0;z<k;z++){
                if(b[z]==a[j]){
                    for(long long w=z;w<k;w++){
                        b[w]=0;
                    }
                }
            }
            b[k]=a[j];
            k++;
        }
        for(long long j=i;j<n;j++){
            if(b[j]!=0){
                for(long long k=0;k<n;k++){
                    if(b[j]==a[k]) c[k]+=1;
                }
            }
        }
    }
    for(long long i=0;i<n;i++){
        cout<<c[i];
    }
    return 0;
}
