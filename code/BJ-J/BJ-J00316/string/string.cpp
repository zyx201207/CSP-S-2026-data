#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
struct node{
    long long len;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long tot=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        tot+=a[i].len;
    }
    long long lp=1,l1=1;
    long long rp=n,r1=a[n].len;
    long long ans=0;
    while(lp<rp){//?是否有边界问题
        long long lcan=a[lp].len-l1+1;//左边可以往后延伸出的最大块
        long long rcan=r1;//右边可以往后延伸出的最大块
        long long can=min(lcan,rcan);
        if(a[lp].c!=a[rp].c){//假如这两段对不上，就改其中一段
            ans+=can;
        }
        //继续往下走
        if(lcan==rcan){
            if(lp+1>=rp-1){
                break;
            }
            lp++;
            rp--;
            l1=1;
            r1=a[rp].len;
        }else if(lcan<rcan){
            lp++;
            l1=1;
            r1-=can;
        }else{
            rp--;
            r1=a[rp].len;
            l1+=can;
        }
    }
    cout<<ans;
    return 0;
}