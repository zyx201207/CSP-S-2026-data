#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[500005],m,pre[500005];
bool check(int len){
    int front=1,back=0;
    for(int i=1;i<=n;i++){
        if(i>=len){
            ll maxn=a[i];
            ll sum=pre[i]-pre[i-len];
            ll need=maxn*len-sum;
            if(need<=m) return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}