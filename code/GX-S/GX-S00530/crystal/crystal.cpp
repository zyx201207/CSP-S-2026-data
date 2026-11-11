#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal4.in","r",stdin);
freopen("crystal4.out","w",stdout);
long long n,m,a[100000],bz,sj=0,jg[100000],n1=0,m1;

cin>>n>>m;
m1=m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}

for(int i=1;i<=n;i++){
    bz=a[i];
    for(int j=1;j<=n;j++){
        if(a[j]>bz){
            if(m>=a[j]-bz){
                m=m-(a[j]-bz);
                sj++;
            }
        }
        else if(a[j]<bz){
            if(m>=bz-a[j]){
                m=m-(bz-a[j]);
                sj++;
            }
        }
        else{
            sj++;
        }
    }
    jg[i]=sj;
    n1++;
    m=m1;
    sj=0;
}

long long mx=jg[1];
for(int i=1;i<=n1;i++){
    if(mx<jg[i]){
        mx=jg[i];
    }
}
cout<<mx;

return 0;
}
