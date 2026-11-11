#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0,s=0,ma=0,c=0,p=0,l=0;
    long long a[500005];
    cin>>n>>m;
    l=m;
    for (long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for (long long i=1;i<=n;i++){
        for(long long j=n;j>0+i;j--){
            if(a[j]>a[j-1] && j!=1){
            s=a[j];
            a[j]=a[j-1];
            a[j-1]=s;
            s=0;
            }
        }
    }
    for (long long i=1;i<=n;i++){
        for (long long j=i;j<=n;j++){
            if(a[i]==a[j]){
                ma+=1;
            }else{
                ma+=1;
                p=a[i]-a[j];
                l=l-p;

                if(l<0){
                    j=n+1;
                    ma-=1;
                }else if(l==0){
                    j=n+1;
                }
                 p=0;
            }

        }
        if(ma>c){
            c=ma;
        }
        ma=0;
        l=m;
    }
    cout<<c;
    return 0;
}
