#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,sum,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ans=cnt=1;
    for(int i=2;i<=n;i++){
        sum+=cnt*(a[i]-a[i-1]);
        while(sum>m){
            sum-=a[i]-a[i-cnt];
            cnt--;
        }
        cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<'\n';
    return 0;
}
//Oct31==Dec25?