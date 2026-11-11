#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],l,ans=2147483647;
bool v[N];
string s[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        int p=a[i];
        while (p){
            s[i]=(char)('0'+p%2)+s[i];
            p/=2;
        }
        l=max(l,(int)s[i].size());
    }
    for (int i=1;i<=n;i++){
        while (s[i].size()<l) s[i]='0'+s[i];
    }
    for (int i=0;i<l;i++){
        int cnt=0;
        for (int j=1;j<=n;j++){
            if (v[j]) continue;
            if (s[j][i]=='1') cnt++;
        }
        if (cnt>=m){
            for (int j=1;j<=n;j++){
            if (s[j][i]=='0') v[j]=1;
        }
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (!v[i]) {
            cnt++;
            ans&=a[i];
            if (cnt==m) break;
        }
    }
    cout<<ans;
    return 0;
}
