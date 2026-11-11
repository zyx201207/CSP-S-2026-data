#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,a[200001],ij=0,cd;
    char c[200001],s[200001];
    freopen("string3.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        cd+=a[i];
    }
    for(long long i=0;i<cd;i++){
        for(long long j=ij;j<=a[i]+ij;j++){
            s[j]=c[i];
        }
        ij+=a[i];
    }
    long long cdc=cd/2,cdd=cd-1;
    if(cd%2==0) cdd-=1;
    long long zs=0;
    for(long long i=0;i<cdc;i++){
    if(s[i]==s[cdd]){
            long long kskbl=2606;
        }else{
            zs+=1;
        }
        cdd-=2;
    }

    cout<<zs;

    return 0;
}
