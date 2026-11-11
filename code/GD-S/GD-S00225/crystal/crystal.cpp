#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n;
long long m;
long long a[N];
long long s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int res=0;
    for(int i=1;i<=n;i++){
        int l,r;
        l=0;
        r=i+1;
        while(l+1<r){
            int mid=((l+r)>>1);
            if(mid*a[i]-(s[i]-s[i-mid])<=m)l=mid;
            else r=mid;
        }
        res=max(res,l);
    }
    cout<<res<<"\n";
}