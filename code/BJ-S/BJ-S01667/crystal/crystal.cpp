#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;

int n,ans;
ll m,a[N],s[N];
bool check(int len){
    for(int i=len;i<=n;i++){
        if(a[i]*len-(s[i]-s[i-len])<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=max(ans,mid);
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}

