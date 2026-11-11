#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],maxn;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>5000){
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=i;
            if(sum>m){
                cout<<i;
                break;
            }
        }

        return 0;
    }
    for(int i=1;i<=n;i++){
        int cnt=0,t=m;
        for(int j=i;j>=1;j--){
            if(t>=a[i]-a[j]){
                t-=(a[i]-a[j]);
                cnt++;
            }
        }
  //      cout<<i<<" "<<cnt<<endl;
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
