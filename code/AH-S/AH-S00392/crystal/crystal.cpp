#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,m,a[N],maxn,ans,sum[5001][5001],sum2[N][201];
set<int> t;
bool check(int x){
    for(int i=x;i<=n;i++){
        if(sum[i][i]-sum[i][i-x]<=m) return 1;
    }
    return 0;
}
bool check2(int x){
    for(int i=x;i<=n;i++){
        if(sum2[i][a[i]]-sum2[i-x][a[i]]<=m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) t.insert(a[i]-a[i-1]);
    if(t.size()==1){
        int sum=0,c=*t.begin();
        for(int i=1;i<=n;i++){
            sum+=(i-1)*c;
            if(sum>m){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    if(maxn<=100){
        for(int i=1;i<=n;i++) a[i]+=100;
        for(int i=1;i<=n;i++){
            for(int j=a[i];j<=200;j++){
                sum2[i][j]=sum2[i-1][j]+j-a[i];
            }
        }
        int l=1,r=n;
        while(l<=r){
            int mid=l+r>>1;
            if(check2(mid)) l=mid+1,ans=mid;
            else r=mid-1;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            sum[i][j]=sum[i][j-1]+abs(a[i]-a[j]);
        }
    }
    int l=1,r=n;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
