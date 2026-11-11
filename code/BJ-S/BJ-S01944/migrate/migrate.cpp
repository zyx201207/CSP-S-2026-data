#include<bits/stdc++.h>
using namespace std;

long long a[1145140*2];
int pre[1145140*2],nxt[1145140*2];

int prel[1145140*2],prer[1145140*2];
int nxtl[1145140*2],nxtr[1145140*2];

int preans[1145140*2],nxtans[1145140*2];
long long sump[1145140*2],sumn[1145140*2];

void work(){
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=-4000000000000000000ll;
    a[n+1]=4000000000000000000ll;
    
    for(int i=1;i<=n;i++)prel[i]=nxtl[i]=n+1,prer[i]=nxtr[i]=0;
    //get nxt
    int nownxt=0;
    for(int i=1;i<=n;i++){
        while(a[nownxt+1]<=a[i]+d)nownxt++;
        if(nownxt<=i)continue;
        nxt[i]=nownxt;
        // cout<<i<<' '<<nownxt<<endl;
        prel[nownxt]=min(prel[nownxt],i);
        prer[nownxt]=max(prer[nownxt],i);
    }
    //get pre
    int nowpre=n+1;
    for(int i=n;i>=1;i--){
        while(a[nowpre-1]>=a[i]-d)nowpre--;
        if(nowpre>=i)continue;
        pre[i]=nowpre;
        // cout<<i<<' '<<nowpre<<endl;
        nxtl[nowpre]=min(nxtl[nowpre],i);
        nxtr[nowpre]=max(nxtr[nowpre],i);
    }

    // for(int i=1;i<=n;i++)cout<<prel[i]<<' '<<prer[i]<<' '<<nxtl[i]<<' '<<nxtr[i]<<endl;
    //calc preans
    sump[0]=0;
    for(int i=1;i<=n;i++){
        preans[i]=1;
        if(pre[i]>=prel[i])preans[i]+=preans[pre[i]];
        preans[i]+=max(0,min(prer[i]-pre[i],prer[i]-prel[i]+1));
    }
    // for(int i=1;i<=n;i++)cout<<preans[i]<<' ';cout<<endl;
    //calc nxtans
    sumn[n+1]=0;
    for(int i=n;i>0;i--){
        nxtans[i]=1;
        if(nxt[i]<=nxtr[i])nxtans[i]+=nxtans[nxt[i]];
        nxtans[i]+=max(0,min(nxtr[i]-nxtl[i]+1,nxt[i]-nxtl[i]));
    }
    // for(int i=1;i<=n;i++)cout<<nxtans[i]<<' ';cout<<endl;
    //calc ans
    for(int i=1;i<=n;i++)prer[i]=min(prer[i],i-2);
    for(int i=1;i<=n;i++)nxtl[i]=max(nxtl[i],i+2);
    
    long long ans=0;
    for(int i=2;i<=n;i++){
        long long preval=0,nxtval=0;
        if(prer[i]>=prel[i]&&pre[i-1]<=prer[i]) {
            if(pre[i-1]>=prel[i])preval+=preans[pre[i-1]];
            preval+=max(0,min(prer[i]-prel[i]+1,prer[i]-pre[i-1]));
        }
        if(nxtl[i-1]<=nxtr[i-1]&&nxt[i]>=nxtl[i-1]){
            if(nxt[i]<=nxtr[i-1])nxtval+=nxtans[nxt[i]];
            nxtval+=max(0,min(nxtr[i-1]-nxtl[i-1]+1,nxt[i]-nxtl[i-1]));
        }
        // cout<<i<<' '<<preval<<' '<<nxtval<<endl;
        ans+=preval*nxtval;
    }
    cout<<ans<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    while(t--)work();
}

//还是没给最后一个大洋里