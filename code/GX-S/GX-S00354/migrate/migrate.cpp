#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
const int N=2000000+10;
int c,t;
int n,d;
int s[N],ans=0;
vector<int>vec;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        ans=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&s[i]);
        s[0]=-0x3f3f3f3f;
        s[n+1]=0x3f3f3f3f;
        for(int i=1;i<=n-2;i++)
            if(s[i+1]-s[i]<=d&&s[i+2]-s[i]<=d&&s[i+3]-s[i+1]<=d&&s[i+3]-s[i+2]<=d&&s[i+3]-s[i+0]>d)
                vec.push_back(i);
        //for(int i=0;i<(int)vec.size();i++)
        //    cout<<vec[i]<<" ";
        //cout<<endl;
        for(int i=0;i<(int)vec.size();i++)
        {
            int l=vec[i],r=vec[i]+3,el=0,er=n+1,ll=1,lr=1;
            if(i>=1)
                el=vec[i-1];
            else if(i<(int)vec.size()-1)
                er=vec[i+1]+3;
            for(;l>el+1&&s[l]-s[l-1]<=d;l--,ll++);
            for(;r<er-1&&s[r+1]-s[r]<=d;r++,lr++);
            //cout<<l<<" "<<r<<" "<<el<<" "<<er<<" "<<ll<<" "<<lr<<endl;
            ans+=ll*lr;
        }
        vec.clear();
        cout<<ans<<endl;
    }
    return 0;
}
