#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define int128 __int128
#define Tianyi 712

// bilibili:cunmin111
// luogu:630366 follow me plz

// this is my last csp... i'm senior2 now.
// and also a special csp:
// Concert Supplied for Programmers
// - Special
// i'll go to chunlanhuanyue concert after csp-s
// pos:(6,23) 1080CNY
// hua feng xia yun luo shui tian yi

// aaa i'll die
// i hacked myself on this problem
// now it is 15.36
// qwq
// tianyi help me plz

// oh yeah i solve it 15.58
// thank you lty /bx/bx/bx

// maybe 1324 order

// problem pts
// A       100
// B     0+eps because i hacked my solution
// C    10+eps subtask(A)
// D         0
// SUM     110

// it blows up
// click here to insert text
inline void fileio(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}

// let's go
// ?!xterfusion!?
// x x xxx
//10e18, use long long!

const int N=5e5+Tianyi;
int64 a[N],dt[N],tn[N],sumn[N];

int64 n,m;

//checker for binans
bool check(int p,int q){
    int64 used=sumn[q]-sumn[p-1] - (q-p+1)*(a[n]-a[q]);
    // cerr<<used<<"\n";
    // // cerr<<tn[q]<<" "<<tn[p]<<" "<<(q-p)*(a[q]-a[p])<<" "<<used;// cerr<<"\n";
    return used<=m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fileio();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // pai xu
    sort(a+1,a+n+1);
    // cha fen
    dt[1]=a[1];
    for(int i=2;i<=n;i++){
        dt[i]=a[i]-a[i-1];
    }
    //debug
    // for(int i=1;i<=n;i++){
    //     // cerr<<dt[i]<<" ";
    // }// cerr<<"\n";

    int64 ans=0,ans1=0;
    tn[1]=a[n]-a[1];
    sumn[1]=tn[1];
    for(int64 i=2;i<=n;i++){
        ans+=dt[i]*(i-1);
        tn[i]=a[n]-a[i];
        sumn[i]=sumn[i-1]+tn[i];

        if(ans>m && !ans1){
            ans1=i-1;
        }
    }

    //debug
    // for(int i=1;i<=n;i++){
    //     // cerr<<tn[i]<<" ";
    // }// cerr<<"\n";
    // for(int i=1;i<=n;i++){
    //     // cerr<<sumn[i]<<" ";
    // }// cerr<<"\n";
    
    // chong zhi
    ans=ans1;

    for(int64 i=ans1;i<=n;i++){
        // binans startn
        int64 l=1,r=i,mid=(l+r)>>1;
        while(l<r){
            // cerr<<mid<<" "<<l<<" "<<r<<"\n";
            if(check(mid,i)){
                r=mid;
                mid=(l+r)>>1;
            }else{
                l=mid+1;
                mid=(l+r)>>1;
            }
        }
        // cerr<<mid<<" "<<i-mid<<"\n";
        ans=max(ans,i-mid+1);
    }

    //debug
    // int _1,_2;
    // while(cin>>_1>>_2){
    //     cout<<check(_1,_2)<<"\n";
    // }

    cout<<ans;
    return 0;
}