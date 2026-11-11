#include<bits/stdc++.h>
#define int long long
#define db double
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N],suma[N];
int ans;
int rd() {
    int num=0,k=1,c=getchar();
    while(!isdigit(c)) {
        if(c=='-') k=-1;
        c=getchar();
    }
    while(isdigit(c)) {
        num=num*10+c-48;
        c=getchar();
    }
    return num*k;
}
int cost(int l,int r) {//make each one from a[l] to a[r-1] add to a[r];
    return a[r]*((r-1)-l+1)-(suma[r-1]-suma[l-1]);
}
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd(),m=rd();
    for(int i=1;i<=n;i++) {
        a[i]=rd();
    }
    sort(a+1,a+n+1);
    a[n+1]=inf;
    vector<int> pos;
    for(int i=1;i<=n;i++) {
        suma[i]=suma[i-1]+a[i];
        if(a[i+1]!=a[i]) pos.push_back(i);
    }
    for(int r:pos) {
        int L=1,R=r;
        while(L<R) {
            int mid=(L+R)>>1;
            if(cost(mid,r)>m) L=mid+1;
            else R=mid;
        }
        ans=max(ans,r-L+1);
    }
    cout<<ans;
    return 0;
}
/*
information:
    n<=5e5, m<=1e18, |a[i]|<=1e12

    method time: O(nlog n)

only the same a[i] and a[j] can be combined
each update can make one a[i] add 1

the more clear explaination:
    total /m/ updates. each update can make one a[i] add 1. make the final same number become the max.

*/