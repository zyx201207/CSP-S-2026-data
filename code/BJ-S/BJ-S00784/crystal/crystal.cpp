#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,mod=1e9+7,INF=1e18;
int a[N],s[N];
int n,m;
bool get(int x){
    for(int i=1;i+x-1<=n;i++){
        int j=i+x-1;
        if(a[j]*x-(s[j]-s[i-1])<=m){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(get(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
//erfen ans  1 1
