#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define fi first
#define se second
#define loop(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rloop(i,a,b) for(int i=(a);(i)>=(b);(i)--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;

const int N=2e6+5;
const int mod=1e9+7;
const ll inf=2e18;

int c,T,n;
ll d,x[N];
int col[N],color,L[N],R[N];
int tot;
struct node{
    int l,r;
}f[N];

ll brute(){
    tot=0;
    loop(l,1,n-3)loop(r,l+3,n)if(x[r]-x[l]>d&&col[l]==col[r]){
        int cnt=0;
        loop(i,l,r){
            if(x[i]-x[l]<=d&&x[r]-x[i]<=d)if(++cnt>2)break;
        }
        if(cnt==2)f[++tot]={l++,r};
    }
    ll ans=0;
    f[0]={0,3},f[tot+1]={n-2,n+1};
    // cout<<tot<<'\n';
    loop(i,1,tot){
        // cout<<f[i].l<<' '<<f[i].r<<' ';
        // cout<<f[i].l-max(L[col[f[i].l]]-1,f[i-1].l)<<' ';
        // cout<<min(f[i+1].r,R[col[f[i].r]]+1)-f[i].r<<'\n';
        ans+=1ll*(f[i].l-max(L[col[f[i].l]]-1,f[i-1].l))*(min(f[i+1].r,R[col[f[i].r]]+1)-f[i].r);
    }
    return ans;
}

ll solve(){
    cin>>n>>d;
    loop(i,1,n)cin>>x[i];
    color=1;
    L[color]=1;
    loop(i,1,n-1){
        col[i]=color;
        if(x[i+1]-x[i]>d)R[color]=i,L[++color]=i+1;
    }
    col[n]=color;
    R[color]=n;
    // loop(i,1,color)cout<<L[i]<<' '<<R[i]<<'\n';
    if(n<=300)return brute();
    tot=0;
    loop(r,4,n){
        int l=lower_bound(x+1,x+1+n,x[r]-d)-x;
        // cout<<l<<' ';
        // cout<<'\n';
    }
    // cout<<tot<<'\n';
    ll ans=0;
    f[0]={0,3},f[tot+1]={n-2,n+1};
    loop(i,1,tot){
        // cout<<f[i].l<<' '<<f[i].r<<' ';
        // cout<<f[i].l-max(L[col[f[i].l]]-1,f[i-1].l)<<' ';
        // cout<<min(f[i+1].r,R[col[f[i].r]]+1)-f[i].r<<'\n';
        ans+=1ll*(f[i].l-max(L[col[f[i].l]]-1,f[i-1].l))*(min(f[i+1].r,R[col[f[i].r]]+1)-f[i].r);
    }
    return ans;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)cout<<solve()<<'\n';
    return 0;
}
// g++ migrate.cpp -o migrate -O2 -std=c++14 -static -Wall -Wextra

/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/