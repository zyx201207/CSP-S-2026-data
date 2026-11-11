#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],sum=0;
char c[200010];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum+=a[i];
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    for(int i=0;i<(sum>>1);i++){
        if(s[i]!=s[sum-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
