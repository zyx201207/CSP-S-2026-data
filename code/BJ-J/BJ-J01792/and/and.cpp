#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m;
int arr[N];
bool v[N][67];
int cnt[67];
vector<int> ok;
queue<int> q;
void gengxin()
{
    ok.clear();
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        ok.push_back(t);
    }
    return ;
}
void huibao()
{
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<":";
        for(int poww=0;poww<=31;poww++)
        {
            if(v[i][poww])
                cout<<poww<<" ";
        }
        cout<<'\n';
    }
    for(int poww=0;poww<=31;poww++)
    {
        cout<<cnt[poww]<<" ";
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        for(int poww=0;poww<=31;poww++)
        {
            int temp=1<<poww;
            if(arr[i]&temp)
                v[i][poww]=1;
            else
                v[i][poww]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int poww=0;poww<=31;poww++)
        {
            if(v[i][poww])
                cnt[poww]++;
        }
        ok.push_back(i);
    }
    //huibao();    //running is ok!!!
    for(int i=31;i>=0;i--)
    {
        if(cnt[i]<m)
            continue;
        if(cnt[i]>=m)
        {
            //cout<<"in:"<<i<<"\n";
            int idx=-1;
            for(auto j : ok)
            {
                idx++;
                if(!v[j][i])
                {
                    for(int k=0;k<=31;k++)
                    {
                        if(v[j][k])
                            cnt[k]--;
                    }
                    //cout<<"i:"<<i<<" j:"<<j<<'\n';
                }
                else
                    q.push(j);

            }
        }
        gengxin();
    }
    int ans=(1<<31)-1;
    int cnt=0;
    for(auto i : ok)
    {
        //cout<<i<<" ";
        if(cnt>=m)
            break;
        ans&=arr[i];
        cnt++;
    }
    cout<<ans;
    return 0;
}
