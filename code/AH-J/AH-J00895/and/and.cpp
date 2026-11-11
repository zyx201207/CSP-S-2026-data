#include<bits/stdc++.h>
//define int long long
using namespace std;
int arr[200005];
bool no_choose[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int a=(1<<29);
    for(int i=30;i>=1;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
            if((arr[j]&a)==0||no_choose[j])cnt++;
        if(n-cnt>=m)
        {
            ans+=a;
            for(int j=1;j<=n;j++)
                if((arr[j]&a)==0)no_choose[j]=1;
        }
        a>>=1;
    }
    cout<<ans;
    return 0;
}
