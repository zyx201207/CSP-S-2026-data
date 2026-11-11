#include<bits/stdc++.h>
using namespace std;
long long n,g,c,t;
char z[1000000010],f[1000000010],l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>g>>l;
        for(long long j=1;j<=g;j++){
            z[c]=l;
            c++;
        }
    }
    for(long long i=c;i>=0;i--){
        f[c-i]=z[i];
    }
    for(long long i=0;i<c;i++){
        if(f[i]!=z[i]) t++;
    }
    cout<<t/2;
    return 0;
}
