#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],res[500005];
int ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        //cout<<i<<":"<<endl;
        int cnt=1,l=m;
        for(int j=i-1;j>=1;j--){
            //cout<<"j="<<j<<":"<<endl;
            int f=a[i]-a[j];
            if(f<=l){
                l=l-f;
                cnt++;
            }
            else{
                break;
            }
        }
        //cout<<cnt<<endl;
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
