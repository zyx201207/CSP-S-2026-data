#include<bits/stdc++.h>
using namespace std;
long long a[500002]={0};
long long n,m;
long long read(){
    long long all=0;bool minues=false;
    char s;
    while(1){
        s=getchar();
        if((s<'0'||s>'9')&&s!='-'){break;}
        if(s=='-'){minues=true;continue;}
        all=all*10+s-'0';
    }
    if(minues==true){return -all;}
    else{return all;}
}
long long turoner(int stai){
    long long all=1,v=m;
    for(int j=stai;j<=n;j++){
        if(v-(a[j]-a[j-1])*(j-1)>=0){
            v-=(a[j]-a[j-1])*(j-1);
            all++;
        }
        else{break;}
    }
    return all;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){a[i]=read();}
    sort(a+1,a+1+n);

    long long maxall=-LONG_MAX;
    for(int i=2;i<=n;i++){
        maxall=max(turoner(i),maxall);
    }
    cout<<maxall;
    return 0;
}
