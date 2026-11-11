#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000005;
ll n,m;
ll a[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,ans=0;
    for(int i=1;i<=n;i++){
        while(a[i]*(i-l+1)-(pre[i]-pre[l-1])>m){
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
