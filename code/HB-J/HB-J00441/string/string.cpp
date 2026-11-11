#include<bits/stdc++.h>
#define int long long
#define pi 3.1415926
using namespace std;
int n,cnt,ans;
int a[200005];
char s[200005];
string k;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        for(int j=1;j<=a[i];j++){
            k[j+cnt]=s[i];
        }
        cnt+=a[i];
    }
    for(int i=1;i<=cnt/2;i++){
        if(k[i]!=k[cnt-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
