#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int len=-1,sum=0;
    for(int i=1;i<=n;i++){
        len++;
        sum+=len*(a[i]-a[i-1]);
        while(sum>m){
            sum-=a[i]-a[i-len];
            len--;
        }
        ans=max(ans,len+1);
    }
    cout<<ans;
}
