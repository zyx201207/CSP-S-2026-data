#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,maxn;
int a[N],sum[N];
bool check(int x,int p){
    int s=(p-x+1)*a[p];
    int ss=sum[p]-sum[x-1];
    if(s-ss<=m)return 0;
    return 1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid,i)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        maxn=max(maxn,i-l+1);
    }
    cout<<maxn;
}
