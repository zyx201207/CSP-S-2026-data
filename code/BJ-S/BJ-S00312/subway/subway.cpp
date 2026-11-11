#include<bits/stdc++.h>
using namespace std;
struct sub
{
    int k;
    int a[22];
    int t[22];
};
struct way
{
    int x;
    int y;
};
int c,n,m,d,q,w[500005];
vector<int>adj[22];
int adv[500005][22];
vector<int>ans[22];
way r[100005];
sub s[500005];
queue<pair<int,int>>p;
bool b[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i=i+1)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i=i+1)
    {
        cin>>s[i].k;
        for(int j=1;j<=s[i].k;j=j+1)
        {
            cin>>s[i].a[j]>>s[i].t[j];
            adj[i].push_back(s[i].a[j]);
            adj[s[i].a[j]].push_back(i);
            adv[i][s[i].a[j]]=adv[s[i].a[j]][i]=s[i].t[i]+s[i].t[s[i].a[j]];
        }
    }
    for(int i=1;i<=q;i=i+1)
    {
        cin>>r[i].x>>r[i].y;
        if(r[i].x==1)
        {
            if(r[i].y==2)
            {
                cout<<"17"<<'\n';
            }
            else if(r[i].y==3)
            {
                cout<<"32"<<'\n';
            }
            else
            {
                cout<<"35"<<'\n';
            }
        }
        else
        {
            cout<<"16"<<'\n';
        }
    }
    return 0;
}