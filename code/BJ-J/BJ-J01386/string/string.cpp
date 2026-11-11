#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
const int N =2e5+5;
int n;
struct nod{
    int cnt;
    char c;
}a[N];
int ans=0;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    rep(i,1,n)cin>>a[i].cnt>>a[i].c;
    for(int i=1,j=n;i<=n&&j;i++){
        if(i>=j) break;
        while(j&&a[j].cnt<=a[i].cnt&&j>i){
            ans+=a[j].cnt*(a[i].c!=a[j].c?1:0);
            a[i].cnt-=a[j].cnt;
            j--;
        }
        if(i>=j) break;
        if(a[j].cnt>a[i].cnt){
            ans+=a[i].cnt*(a[i].c!=a[j].c?1:0);
            a[j].cnt-=a[i].cnt;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

