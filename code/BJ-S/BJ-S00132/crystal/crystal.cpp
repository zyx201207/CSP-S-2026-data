#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long add[500005];
bool ff1=1;
bool ff2=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            ff1=0;
        }
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
            ff2=0;
        }
    }
    if(ff1){
        for(int i=n;i>=1;i--){
            long long check=i*(i-1);
            check=check/2;
            if(m>=check){
                cout<<i;
                return 0;
            }
        }
    }
    if(ff2){
        long long sum=a[2]-a[1];
        for(int i=n;i>=1;i--){
            long long b=a[n]-a[n-i+1];
            long long check=(b+sum)*(i-1);
            check=check/2;
            if(m>=check){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        add[i]=add[i-1]+a[i];

    }
    bool f=0;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            long long check=add[j]-add[j-i]+m;
            if(check>=i*a[j]){
                cout<<i;
                f=1;
                break;
            }
        }
        if(f){
            break;
        }
    }
    return 0;
}