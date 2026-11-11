#include <bits/stdc++.h>
using namespace std;
int mn(int s,int w){
    for(int i=1;i<=200005;i++){
        if(s==1 && w==1){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,b[200005],c,d=0,f,h,k,g[200005],m[200005],n[200005],o=0;
cin>>a>>c;
int e[200005];
e[0]=999999;
for(int i=1;i<=a;i++){
    cin>>b[i];
    }
for(int i=1;i<=a;i++){
    for(int j=1;j<=a;j++){
        if(b[j]<=e[i-1]&&b[j]>e[i]){
            e[i]=b[j];
        }
    }
}
for(int i=1;i<=c;i++){
    h=e[i];
    while(h==0){
        int j=1;
        g[j]=h%2;
        h/2;
        k=j;
        j++;
    }
    if(i==1){
    for(int j=1;j<=200005;j++){
            n[j]=g[j];
        }
    }
    for(int j=1;j<=200005;j++){
        n[j]=mn(m[j],g[j]);
    }
    for(int j=1;j<=k;j++){
        m[j]=g[j];
    }
    for(int j=1;j<=200005;j++){
        g[j]=0;
    }

}
for(int i=1;i<=200005;i++){
    o+=m[i]*(i-1);
}
cout<<o;
return 0;
}
