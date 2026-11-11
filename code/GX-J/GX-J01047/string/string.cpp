#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,n,g[10001];
string m[10001];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>g[n]>>m[n];
    }
    for(long long i=1;i<=n;i++){
        a+=g[n];
    }
    if(a%2==0) b=a/2;
    else c=a/2+1;
    for(long long i=1;i<=b;i++){
        if(m[i+b]==m[i]) continue;
        else{
            d+=g[i+b];
        }
    }
    for(long long i=1;i<=c-1;i++){
        if(m[i+c]==m[i]) continue;
        else{
            d+=g[i+c];
        }
    }
    if(c>0){
        if(g[c]%2==0){
            d+=1;
        }
    }
    cout<<d;
    return 0;
}
