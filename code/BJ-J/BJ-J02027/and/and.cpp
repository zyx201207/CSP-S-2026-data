#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
const int N=31;
int n,m;
int a[200200];
string s[200200];
vector<int>vt[N+5];

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int u=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int yy=a[i];
        int q=pow(2,30);
        for(int j=1;j<=31;j++)
        {
            s[i].push_back(yy/q+'0');
            if(yy/q) vt[31-j].push_back(i);
            if(yy/q) u=max(u,31-j);
            yy%=q;
            q/=2;
        }
    }
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<s[i]<<endl;
    //}
    //for(int i=0;i<31;i++)
    //{
    //    cout<<i<<' '<<vt[i].size()<<' ';
    //    for(int j=0;j<vt[i].size();j++) cout<<vt[i][j]<<' ';
    //    cout<<endl;
    //}
    int k=0;
    vector<int>cur;
    for(int i=u;i>=0;i--)
    {
        //cout<<i<<' '<<vt[i].size()<<endl;
        if(vt[i].size()>=m)
        {
            k=i;
            cur=vt[i];
            break;
        }
    }
    //cout<<k<<endl;
    for(int i=k;i>=0;i--)
    {
        vector<int>v;
        int cnt=0;
        for(int j=0;j<cur.size();j++)
        {
            if(s[cur[j]][31-i]=='1')
            {
                cnt++;
                v.push_back(cur[j]);
            }
        }
        if(cnt>=m) cur=v;
        //for(int j=0;j<cur.size();j++)
        //{
            //cout<<a[cur[j]]<<' ';
        //}
        //cout<<endl;
    }
    int ans=INT_MAX;
    for(int i=0;i<cur.size();i++)
    {
        ans&=a[cur[i]];
        //cout<<a[cur[i]]<<' ';
    }
    cout<<(ans==INT_MAX?0:ans);
    return 0;
}
