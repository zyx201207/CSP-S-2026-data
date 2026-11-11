#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],flag[500010],f[500010],dp[300010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        memset(f,0,sizeof(f));
        string s;
        for(int j=i;j<=n;j++){
            flag[a[j]]++;
            if(flag[a[j]]!=1){
                s.erase(f[a[j]]);
                flag[a[j]]=1;
            }
            f[a[j]]=j-1;
            s+=char(a[j]);
        }
        for(int i=0;i<s.size();i++){
            dp[(int)(s[i])]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<dp[i]<<" ";
    return 0;
}
