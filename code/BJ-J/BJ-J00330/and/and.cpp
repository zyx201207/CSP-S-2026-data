#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
int n,m,a[maxn],ans;
bool ok[maxn];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],ok[i]=1;
    for(int i=32;i>=0;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            if((a[j]&(1ll<<i))!=0&&ok[j])sum++;
        }//cout<<i<<' '<<sum<<'\n';
        if(sum>=m){
            for(int j=1;j<=n;j++){
                if((a[j]&(1ll<<i))==0&&ok[j])ok[j]=0;
            }ans|=1ll<<i;
        }
    }
    cout<<ans;
    return 0;
}
