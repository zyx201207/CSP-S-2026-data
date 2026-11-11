#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,a[N],maxn=-1e9;
bool cmp(int x,int y){return x>y;}
signed main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    int ans=a[1];
    for(int i=1;i<=m;i++) ans&=a[i];
    cout<<ans<<endl;
    return 0;
}
