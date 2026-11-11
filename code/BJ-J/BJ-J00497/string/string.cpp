#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,w;
long long l;
long long ans;
char z[100003];
long long s[100003];

char find (long long a){
    long long jl=0;
    long long wz=0;
    for(long long i=1;i<=l;i++){
        if(wz+s[i]<=a){
            wz+=s[i];
            jl++;
            //cout<<"1:"<<jl<<endl<<wz<<endl;
        }
        if(wz==a){
            //cout<<"2:"<<jl<<endl<<wz<<endl;
            return z[jl];break;
        }
        if(wz<a&&wz+s[i]>=a){
            jl++;
            //cout<<"3:"<<jl<<endl<<wz<<endl;
            return z[jl];break;
        }
    }
    return z[jl];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        s[i]=a;
        z[i]=c;
        l+=a;
    }
    for(long long i=1;i<l/2;i++){
        //cout<<i<<":"<<find(i)<<endl;
        //cout<<l+1-i<<":"<<find(l+1-i)<<endl;
        if(find(i)!=find(l+1-i)){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}

