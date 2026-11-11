#include<iostream>
using namespace std;
#define int unsigned long long
struct zh{
    int shu;
    char zm;
}zuo[2000001],you[200001];
int n,a[200001],bj[200001],zztp,yztp,ans;
char c[200001];
void xc(zh a,zh b){
    int zqk=0,yqk=0;
    if(a.shu<b.shu){
        you[yztp].shu-=zuo[zztp].shu;
        if(a.zm!=b.zm) ans+=a.shu;
        zqk=1;
    }else if(a.shu>b.shu){
        zuo[zztp].shu-=you[yztp].shu;
        if(a.zm!=b.zm) ans+=b.shu;
        yqk=1;
    }else{
        if(a.zm!=b.zm) ans+=b.shu;
        zqk=yqk=1;
    }if(zqk) zuo[zztp--].shu=0;
    if(yqk) you[yztp--].shu=0;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }for(int i=1;i<=n;i++){
        int xbj1,xbj2;
        if(!bj[i]&&!zztp){
            zuo[++zztp].shu=a[i];
            zuo[zztp].zm=c[i];
            xbj1==1;
        }if(!bj[n-i+1]&&!yztp){
            you[++yztp].shu=a[n-i+1];
            you[yztp].zm=c[n-i+1];
            xbj2=1;
        }xc(zuo[zztp],you[yztp]);
        if(bj[n-i+1]||bj[i]){
            cout<<ans;
            return 0;
        }if(xbj1) bj[i]=1;
        if(xbj2) bj[n-i+1]=1;
    }cout<<ans;
    return 0;
}
