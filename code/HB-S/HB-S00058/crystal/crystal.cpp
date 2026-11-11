#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,ans,cnt,tmp;
bool f;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int mid=1;mid<=n;mid++){
        cnt=0;
        f=false;
        tmp=0;
        for(int i=n;i>=1;i--){
            if(a[i]>a[mid]) continue;
            cnt+=(a[mid]-a[i]);
            tmp++;
            if(cnt>m){
                ans=max(ans,1ll*tmp-i-1);
                f=true;
                tmp--;
                break;
            }
        }
        if(!f) ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}
