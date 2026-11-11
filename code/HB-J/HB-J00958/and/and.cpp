#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mx,k=0,ans1,ans2;
bool b[200010][40],dp[200010][200010][40],ans[40];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;pow(2,j)<=a[i];j++){
            b[i][31-j]=a[i]%2;
            a[i]/=2;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<32;j++)dp[i][1][j]=b[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
            for(int k=31;k>=0;k--){
                ans[k]=dp[i][j][k] && b[i][k];
            }
            for(int k=2;k<32;k++){
                ans1+=ans[k]*pow(2,30-k);
                ans2+=dp[i][j][k-1];
            }
            mx=max(ans1,ans2);
        }
    }
    cout << mx;
    return 0;
}
