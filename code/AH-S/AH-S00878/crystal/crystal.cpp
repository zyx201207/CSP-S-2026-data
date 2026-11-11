#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int ans[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m<=100000){
        sort(a+1,a+n+1);
        int maxn=0;
        for(int i=2;i<=n;i++){
            int ans=0,j=i-1;
            while(j>=1&&ans+(a[i]-a[j])<=m){
                ans+=(a[i]-a[j]);
                j--;
            }
            j+=1;
            if(ans==m) maxn=max(maxn,i-j+1);
        }
        cout<<maxn;
    }else{
        int ans=a[2]-a[1];
        int sum=0,i=ans,x=m/ans,cnt=0;
        while(sum<=x){
            cnt++;
            sum+=i;
            i+=ans;
        }
        cout<<cnt;
    }
    return 0;
}
