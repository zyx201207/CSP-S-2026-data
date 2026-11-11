#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>sel;
int a[200005];
bool p[200005][32];
map<int,bool>sur;
void bifill(int n)
{
    for(int k=0;k<=30;++k)
    {
        //if((2<<k)>n)break;
        if((n>>k)&1)p[n][k]=1;
    }
    return;
}//O(logn)
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,maxn=-1;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sur[a[i]]=1;
        bifill(a[i]);
    }
    bool flag=0;
    for(int k=30;k>=0;--k)
    {
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            if(p[a[i]][k] and sur[a[i]])sum++;
        }
        //cout<<sum<<"\n";
        if(!flag and sum<m)continue;
        if(flag)
        {
            if(sum<=m)continue;
            for(auto it:sel)
            {

                if(p[it][k] and sur[it])
                {


                    continue;
                }
                sur[it]=0;
            }
        }
        if(sum>=m and !flag)
        {
            flag=1;

            for(int i=1;i<=n;++i)
            {
                if(p[a[i]][k] and sur[a[i]])sel.push_back(a[i]);
                if(!p[a[i]][k])sur[a[i]]=0;
            }
        }

    }
    vector<int>ans;
    int chos=0;
    for(auto it:sel)
    {
        if(chos<m and sur[it])
        {
            ans.push_back(it);
            chos++;
        }
       // cout<<it<<" "<<sur[it]<<"\n";
    }
    int res=ans.front();
    for(auto it:ans)
    {
        //cout<<it<<" ";
        res=res&it;
    }
    cout<<res;

    return 0;
}
/*
6 4
15 7 3 5 7 22
*/


