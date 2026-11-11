#include<algorithm>
#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;
const int N=5e5+5;
int n;
long long a[N],m;
bool check(int x){
    //cerr<<x<<endl;
    long long cnt=0;
    for(int i=1;i<=x;++i)cnt+=a[x]-a[i];
    long long res=cnt;
    for(int i=x+1;i<=n;++i){
        cnt-=a[i]-a[i-x+1];
        cnt+=x*(a[i]-a[i-1]);
        res=min(res,cnt);
    }
    return res<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
