#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
const int N =2e5+5;
int n,m;
int a[N];
multiset<int>s;
int ans=0;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i],s.insert(a[i]);
    per(bit,30,0)
    {
        //if(bit<=2)for(auto v:s) cout<<v<<' ';
        int cnt =0;
        for(auto v:s) if((v>>bit)&1) cnt++;
        //cout<<"wei:"<<bit<<' '<<cnt<<'\n';
        if(cnt<m)continue;
        auto it=s.begin();
        for(; it!=s.end();)
        {
            //cout<<((*it>>bit)&1)<<'\n';
            if(!((*it>>bit)&1)) it=s.erase(it);
            else it++;
        }
        ans+=(1<<bit);
    }
    cout<<ans;
    return 0;
}

