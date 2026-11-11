#include<bits/stdc++.h>
using namespace std;
bool t(long long b,long long c){
    return b>c;
}
long long a[2000000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;

    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    int maxn=0
    if(m==1){
        for(long long i=1;i<=n-1;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(long long i=1;i<=n-1;i++){
            for(long long j=2;j<=n;i++){

                        long long d=a[i]&a[j];
                        maxn=max(maxn,d);


            }
            cout<<maxn;
            return 0;
        }
    }
     if(m==3){
        for(long long i=1;i<=n-1;i++){
            for(long long j=2;j<=n;i++){
                    for(long long k=3;k<=n;k++){
                        long long d=a[i]&a[j]&a[k];
                        maxn=max(maxn,d);
                    }

            }
            cout<<maxn;
            return 0;
        }
    }
    return 0;
    }
