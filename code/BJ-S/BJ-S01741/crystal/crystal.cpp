#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],ans=0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int c=a[2]-a[1];
    int t=m;
    for(int i=1;;i++){
        if(t-i*c<0){
            ans=i;
            break;
        }else t-=i*c;
    }
    cout<<ans;

    return 0;
}
