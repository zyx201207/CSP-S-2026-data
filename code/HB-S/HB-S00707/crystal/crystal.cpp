#include<bits/stdc++.h>
using namespace std;

const int N=500005;
long long m,A[N],val;
int n,ans;

template<typename qwq>inline void cmin(qwq &a,qwq b){(a>b)&&(a=b);}
template<typename qwq>inline void cmax(qwq &a,qwq b){(a<b)&&(a=b);}

template<typename qwq>inline void read(qwq &a){
    a=0;int c=getchar(),f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) a=10*a+c-'0',c=getchar();
    if(f) a=-a;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++) read(A[i]);
    sort(A+1,A+1+n);
    for(int r=1,l=1;r<=n;r++){//[l,r]
        val+=1ll*(r-l)*(A[r]-A[r-1]);
        for(;val>m;l++) val-=A[r]-A[l];
        cmax(ans,r-l+1);
    }
    return cout<<ans<<'\n',0;
}
/*
code by Wxb2010
14:43 finish crystal
*/