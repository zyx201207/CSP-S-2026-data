#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e5+5;
int a[N];
LL n,m;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    //LL l=0,r=m;
    //while(l<r)
    //{
    //   int mid=(l+r)/2;
    //    if(l<=mid) l=mid+1;
    //else if(r>mid) r=mid;
    //}
    //cout<<l;

    LL mid=n/2+1;
    LL res=1;
    for(int i=1;i<=n;i++) {
        if(a[i]==a[mid])
            res++;
    }
    res-=1;
    LL dist=0;
    for(int i=1;i<=mid;i++)
    {

        dist=dist+a[mid]-a[i];
        res++;
        if(dist==m) {
            cout<<res<<endl;
            return 0;
        }
        else if(dist>m) mid+=1;
    }
    return 0;
}
