#include<bits/stdc++.h>
using namespace std;

long long C,T,n,d,xd,L,R,y,yy;
long long k[2111111],qian[2111111],hou[2111111];

long long findsmall(long long x,long long l,long long r){
    while(l<=r){
        long long mid=(l+r)>>1;
        if(k[mid]>=x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return l;
}

long long findbig(long long x,long long l,long long r){
    while(l<=r){
        long long mid=(l+r)>>1;
        if(k[mid]<=x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return r;
}

long long handle(int x1,int x2){
    return (qian[findsmall(k[x2+1]-d,1,x2)-1]-qian[findsmall(k[x2]-d,1,x2)-1]) * (hou[findbig(k[x1-1]+d,x2,n)+1]-hou[findbig(k[x1]+d,x1,n)+1]);
}

bool keyi(int x1,int x2){
    if(k[findsmall(k[x2]-d,1,x1)]<k[x1] && k[findbig(k[x1]+d,x2,n)]>k[x2]){
        return true;
    }
    return false;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
cin>>C>>T;
for(int tT=1;tT<=T;tT++){
    cin>>n>>d;
    long long ans=0;
    for(int a=1;a<=n;a++){
        cin>>k[a];
    }
    for(int a=1;a<n;a++){
        long long jl1=findsmall(k[a+1]-d,1,a),jl2=findsmall(k[a]-d,1,a);
        qian[a]=qian[jl1-1]-qian[jl2-1]+1;
        qian[a]+=qian[a-1];
        if(qian[a]==qian[a-1]){
            qian[a]++;
        }
    }
    for(int a=n;a>1;a--){
        long long jl1=findbig(k[a-1]+d,a,n),jl2=findbig(k[a]+d,a,n);
        hou[a]=hou[jl1+1]-hou[jl2+1]+1;
        hou[a]+=hou[a+1];
        if(hou[a]==hou[a+1]){
            hou[a]++;
        }
    }
    for(int a=2;a<n-1;a++){
        if(keyi(a,a+1)){
            ans+=handle(a,a+1);
        }
    }
    cout<<ans<<endl;
}
}
