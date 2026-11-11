#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;ll m,a[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int p=1;//严格左端点
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        while(p<=i&&(i-p+1)*a[i]-(pre[i]-pre[p-1])>m){
            ++p;
        }
        ans=max(ans,i-p+1);
    }
    cout<<ans<<'\n';
    return 0;
}