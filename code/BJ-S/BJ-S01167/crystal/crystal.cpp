#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n;ll m,a[maxn],s[maxn];
void slv(){
    scanf("%d%lld",&n,&m);
    up(i,1,n)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    up(i,1,n)s[i]=s[i-1]+a[i];
    auto chk=[&](int l,int r){
        return a[r]*(r-l+1)-(s[r]-s[l-1])<=m;
    };
    int res=0,l=1;
    up(i,1,n){
        while(!chk(l,i))l++;
        res=max(res,i-l+1);
    }
    printf("%d\n",res);
}
int main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    slv();
    return 0;
}