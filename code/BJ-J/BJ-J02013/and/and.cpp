#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int ans,n,m,s[N];
bool flag[N];
void big(int js,int anns,int fl){
    flag[fl]=1;
    if (js>m){
        //out << anns << endl;
        ans=max(ans,anns);
        return;
    }
    for (int j=1;j<=n;j++){
        if (flag[j]==0){

            big(js+1,anns&s[j],j);
        }
    }
}
signed main(){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    if (n==m){
        ans=s[1];
        for (int i=2;i<=n;i++){
            ans&=s[i];
        }
        cout << ans;
        return 0;
    }
    for (int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        big(2,s[i],i);
    }
    cout << ans << endl;
    return 0;
}
