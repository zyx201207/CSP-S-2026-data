#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N=5e5+10;

int n;
long long m;
long long a[N];

void work1() {//暴力 O(n^2)
    long long maxn=0;
    for(int i=1;i<=n;i++) {
        long long cnt=1,val=0;
        for(int j=i+1;j<=n;j++) {
            long long add=a[j]-a[j-1];
            val+=add*cnt;
            if(val>m) break;
            cnt++;
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
}

int get(long long k) { //求一个数T,使得T(T+1)/2<=k<(T+1)(T+2)/2
    long long l=1,r=2e9,ans=0;
    while(l<=r) {
        long long mid=l+r>>1;
        if(mid*(mid+1)/2<=k) ans=mid,l=mid+1;
        else r=mid-1;         
    }
    return ans;
}

void work2() {//等差数列
    long long d=a[2]-a[1];//公差
    m/=d;
    cout<<min(n,get(m)+1);
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=5000) work1();
    else work2();
    return 0;
}