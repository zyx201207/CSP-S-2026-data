#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,lt=0,r=n,rt=0;
    int ans=0;
    while(l<r){
        if(c[l]!=c[r])
            ans+=min(a[l]-lt,a[r]-rt);
        if(a[l]-lt<a[r]-rt){
            rt+=a[l]-lt;
            lt=0;
            l++;
        }else if(a[l]-lt>a[r]-rt){
            lt+=a[r]-rt;
            rt=0;
            r--;
        }else{
            rt=lt=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}