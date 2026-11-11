/*

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],n,ans;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=1,j=n;i<j&&i<=n&&j>=1;){
        int x=min(a[i],a[j]);
        if(c[i]!=c[j]) ans+=x;
        a[i]-=x;
        a[j]-=x;
        if(!a[i]) i++;
        if(!a[j]) j--;
    }
    cout<<ans;
    return 0;
}