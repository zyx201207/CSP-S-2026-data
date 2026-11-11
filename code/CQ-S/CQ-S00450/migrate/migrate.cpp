#include<bits/stdc++.h>
using namespace std;
inline char gtchar(){
    static char buf[1<<21],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline long long read(){
    char ch=gtchar();
    long long x=0;
    bool f=0;
    while(ch<'0'||ch>'9') f|=ch=='-',ch=gtchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gtchar();
    return f?-x:x;
}
int t,n,num1[2000005],num2[2000005],num3[2000005],num4[2000005],pos[2000005];
long long d,x[2000005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(),t=read();
    while(t--){
        n=read(),d=read(),ans=0;
        for(int i=1,j=1;i<=n;i++){
            x[i]=read();
            while(x[j]<x[i]-d) j++;
            if(i==j){num1[i]=num2[i]=num3[i]=num4[i]=0,pos[i]=i;continue;}
            pos[i]=j,num1[i]=num1[j];
            if(x[j+1]-x[pos[j]]>d) num2[i]=num2[j],num3[i]=num3[j],num4[i]=0;
            else if(x[j+2]-x[pos[j]]>d) num2[i]=num3[i]=0,num4[i]=num2[j],num1[i]+=num3[j];
            else num2[i]=num3[i]=num4[i]=0,num1[i]+=num2[j]+num3[j];
            if(x[j+1]-x[pos[j]+1]>d) num3[i]+=num4[j];
            else num1[i]+=num4[j];
            int a=lower_bound(x+pos[j],x+j,x[j+1]-d)-x,b=lower_bound(x+a,x+j,x[j+2]-d)-x;
            num1[i]+=j-b,num4[i]+=b-a,num2[i]+=a-pos[j],ans+=num3[i]+num4[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}