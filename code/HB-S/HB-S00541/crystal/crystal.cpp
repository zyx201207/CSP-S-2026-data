#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;

int n,m,a[N];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    int maxx=(-1)*(1e12+5),minn=1e12+5;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1,ans=0,num=0,cnt=0;
    for (;l<=n;l++)
    {
        for (;r<=n;r++)
        {
            if (r==1||a[r]==a[r-1])
            {
                cnt++;
//                cout<<"<"<<r<<" "<<cnt<<">\n";
            }
            else
            {
                if ((a[r]-a[r-1])*cnt+num<=m)
                {
                    num+=(a[r]-a[r-1])*cnt;
                    cnt++;
//                    cout<<"<"<<r<<" "<<cnt<<">\n";
                }
                else
                {
                    break;
                }
            }
        }
        ans=max(cnt,ans);
        cnt--;
        num-=a[r-1]-a[l];
    }
    
    cout<<ans<<'\n';
    
    return 0;
}