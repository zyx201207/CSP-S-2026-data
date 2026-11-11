#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,h[1000010],sum,ans;
char a[1000010];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>a[i];
        for(int j=1;j<=h[i];j++){
            s+=a[i];
        }
        sum+=h[i];
    }
    for(int i=0,j=sum-1;i!=j;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
