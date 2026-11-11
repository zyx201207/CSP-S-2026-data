#include<bits/stdc++.h>
using namespace std;

int m,n,a[200010],maxs[200010];
int dp[200010]; //共使用m个数时的最大值
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxs[i]=max(maxs[i-1],a[i]);
    }
    if(n==m){
        int p=a[1];
        for(int i=2;i<=n;i++)p&=a[i];
        cout << p;
    }
    else{
        for(int i=1;i<=n;i++){
            dp[0]=a[i];
            for(int j=m;j>=1;j--){
                dp[j]=max(dp[j-1]&a[i],dp[j]);
            }
        }
        cout << dp[m];
    }
}
