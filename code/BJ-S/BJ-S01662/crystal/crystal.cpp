#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005];
bool isA,isB;

void solve1(int d){
    if(d==0) return void(cout << n << endl);
    int k=(-1.0+sqrt(1.0+m/d*8.0))/2.0-10.0;
    if(k>=n) return void(cout << n << endl);
    for(int i=1;i<=20;i++){
        k++;
        if(k<0) continue;
        if(k>n) return void(cout << n << endl);
        int x=k*(k+1)/2.0*d;
        if(x>m) return void(cout << k << endl);
    }
}

void solve2(){
    int ans=1;
    for(int i=2;i<=n;i++){
        int t=m,cur=1;;
        for(int j=i-1;j;j--){
            if(t<a[i]-a[j]) break;
            t-=a[i]-a[j], cur++;
        }
        ans=max(cur,ans);
    }
    cout <<ans << endl;
}

bool chk(int k){
    int ans=1;
    int t=m;
    for(int j=k-1;j>1;j--){
        if(t<a[k]-a[j]) return 0;
        t-=a[k]-a[j];
    }
    return 1;
}

void solve3(){
    int l=1,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(chk(mid)) l=mid;
        else r=mid-1;
    }
    cout << l << endl;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    isA=1;
    for(int i=1;i<=n;i++)
        if(a[i]!=i){isA=0; break;}
    if(isA) return solve1(1), 0;
    int _d=a[2]-a[1]; isB=1;
    for(int i=3;i<=n;i++)
        if(a[i]-a[i-1]!=_d){isB=0; break;}
    if(isB) return solve1(_d), 0;

    sort(a+1,a+1+n);
    if(n<=5000) return solve2(), 0;
    return solve3(), 0;
    return 0;
}
