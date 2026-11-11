#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500099],b[500099];
bool pan(long long p,long long q){
    if(p==q){
        return 1;
    }
long long h=b[q-1]-b[p-1];
long long g=a[q]*(q-p)-h;
if(g>m){return 0;}

else{return 1;}

}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);

for(int i=1;i<=n;i++){

    b[i]=b[i-1]+a[i];
}
long long zui=-1;
for(int i=1;i<=n;i++){
    long long zuo=1,you=i,zhong;
    while(zuo<you){
        zhong=(zuo+you)>>1;
        if(pan(zhong,i)){
            you=zhong;
        }else{zuo=zhong+1;}

    }
    zui=max(zui,i-zuo+1);
}cout<<zui;
return 0;
}
