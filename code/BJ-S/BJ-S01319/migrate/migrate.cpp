#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
long long a[MAXN];
int f[MAXN];
vector<int> v;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            f[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-i-1;
        long long ans=0;
        v.clear();
        v.push_back(0);
        for(int i=1;i<=n;i++)
            if(f[i]==0)
                v.push_back(i);
        for(int k=0;k<v.size()-1;k++)
        {
            int L=v[k]+1,R=v[k+1];
            int tmp=0,pre=L-1;
            for(int i=L;i<=R;i++)
            {
                if(f[i]==2&&f[i+1]>=2)
                {
                    ans+=1LL*tmp*(i-pre);
                    tmp=i-pre;
                    pre=i;
                }
            }
            ans+=1LL*tmp*(R-pre-2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
