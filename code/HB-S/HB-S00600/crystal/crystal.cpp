#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int X=5e5+5;

int N,M,a[X],s[X],res;

inline bool check(int l,int r)
{
    return (r-l+1)*a[r]-(s[r]-s[l-1])<=M;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>a[i];

    sort(a+1,a+N+1);

    for(int i=1;i<=N;i++) s[i]=s[i-1]+a[i];

    for(int i=1;i<=N;i++){
        int l=1, r=i;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid,i)) r=mid;
            else l=mid+1;
        }
        res=max(res,i-l+1);
    }

    cout<<res<<'\n';

}

// g++ -o crystal crystal.cpp -O2 -std=c++14 -static