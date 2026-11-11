#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[600000],del,maxx=-1e14,mmin=1e14,my,dp[600000];
bool checkB=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(a[i],maxx);
        mmin=min(a[i],mmin);
        if(i==2) del=a[2]-a[1];
        if(i>2&&a[i]-a[i-1]!=del) checkB=1;
    }
    sort(a+1,a+1+n);
    if(!checkB){
        for(int i=1;i<=n;i++){
            if(i*(i-1)*del>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    int ans=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            dp[i]=dp[i-1]+1;
            continue;
        }
        int sum=1,my=m;
        for(int j=i-1;j>=1;j--){
            int d=a[i]-a[j];
            if(m>=d){
                m-=d;
                sum++;
            }else break;
        }
        dp[i]=sum;
        m=my;
    }
    int mmaxx=-1e14;
    for(int i=1;i<=n;i++){
        mmaxx=max(mmaxx,dp[i]);
    }
    cout<<mmaxx;
    return 0;
}
