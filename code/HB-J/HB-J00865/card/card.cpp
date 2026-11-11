#include<iostream>
#include<cstring>
using namespace std;

const long long N=5e5+5,M=3e5+5;
long long n,m;
long long a[N];
long long cnt[M];

long long b[N],blen;
long long lastIdx[M];
long long parentIdx[M];
long long vis_chafeng[N];

void yangli(long long l){
    blen=n-l+1;
    for(long long i=l;i<=n;++i)b[i-l+1]=a[i];
    memset(lastIdx,0,sizeof(lastIdx));
    memset(vis_chafeng,0,sizeof(vis_chafeng));
    for(long long i=1;i<=blen;++i)parentIdx[i]=i-1;
    // for(long long i=1,I=blen>>1;i<=I;++i)swap();
    for(long long i=1;i<=blen;++i){
        long long num=b[i];
        long long last_idx=lastIdx[num];
        if(last_idx>0){
            ++vis_chafeng[last_idx];
            --vis_chafeng[i];
            long long p=parentIdx[i];
            while(last_idx<=p){
                lastIdx[b[p]]=0;//ding li da ren gan xie gan xie
                p=parentIdx[p];
                // cout<<" p: "<<p<<"\n";
            }
            // cout<<"pra : \n";
            // for(long long i=1;i<=blen;++i)cout<<parentIdx[i]<<" \n"[i==blen];
            // cout<<"last : \n";
            // for(long long i=1;i<=m;++i)cout<<lastIdx[i]<<" \n"[i==m];
            // cout<<"L R : "<<last_idx<<" "<<i<<" <=> "<<num<<"\n";
            parentIdx[i]=last_idx-1;//p set
        }
        lastIdx[num]=i;
    }
    long long vis=0;
    // cout<<l<<" : \n";
    // for(long long i=1;i<=blen;++i)cout<<b[i]<<" \n"[i==blen];
    // cout<<"vis \n";
    // for(long long i=1;i<=blen;++i)cout<<vis_chafeng[i]<<" \n"[i==blen];
    // vis=0;
    // cout<<"vis \n";
    // for(long long i=1;i<=blen;++i)vis+=vis_chafeng[i],cout<<vis<<" \n"[i==blen];
    // cout<<"STSTSTSTSTSTTST -------------------- \n";
    for(long long i=1;i<=blen;++i){
        vis+=vis_chafeng[i];
        if(vis==0)++cnt[b[i]];
        // ,cout<<b[i]<<" \n"[i==blen]
        // else cout<<" "<<" \n"[i==blen];
    }
    // cout<<"ENDENDNENDNENENE -------------------- \n";
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;++i)cin>>a[i];
    for(long long i=1;i<=n;++i)yangli(i);
    for(long long i=1;i<=m;++i)cout<<cnt[i]<<" \n"[i==m];
    return 0;
}
/*
1 5 7 5 2 0 2 1 4 1 2 3 5
1     5 2 0 2 1 4 1 2 3 5
1     5     2 1 4 1 2 3 5
              1 4 1 2 3 5
                  1 2 3 5
                  1 2 3 5
*/