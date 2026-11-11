#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n,m,maxn=-0x3f3f3f3f,ans;
bool flagB=1;
bool cmp(int a,int b){
    int ca=0,cb=0,ta=a,tb=b;
    while(a){
        if(a&1) ca++;
        a>>=1;
    }
    while(b){
        if(b&1) cb++;
        b>>=1;
    }
    if(ca!=cb) return ca>cb;
    return ta>tb;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=i-1) flagB=0;
    }
    sort(a+1,a+1+n,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    printf("%d",ans);
    return 0;
}
