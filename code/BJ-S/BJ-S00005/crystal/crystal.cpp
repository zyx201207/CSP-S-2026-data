#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
bool f=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]!=a[2]-a[1]){
            f=0;
        }
    }
    if(f){
        if(a[1]==a[2]){
            cout<<n<<"\n";
        }
        else{
            cout<<m/(a[2]-a[1])<<"\n";
        }
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int x=m,cnt=0;
        for(int j=i;j<=n;j++){
            if(a[j]==a[i]){
                cnt++;
            }
        }
        for(int j=i-1;j>=1;j--){
            x-=a[i]-a[j];
            if(x<0){
                break;
            }
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
