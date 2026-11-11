#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll s[N];
int n;
ll d;
ll ans;
set<string> v;
vector<int> f;
int minlen=0x3f3f3f3f;
void DFS(int end,int now,int len,string p)
{
    if(now==end)
    {
        if(len<minlen)
        {
            minlen=len;
            v.clear();
        }
        v.insert(p);
        return;
    }
    for(int i=now+1;i<=end;i++)
    {
        if(s[i]-s[now]<=d) DFS(end,i,len+1,p+to_string(i));
        else break;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        bool w=true;
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++) 
        {
            cin>>s[i];
            if(i>2)
            {
                if(s[i]-s[i-1]!=s[i-1]-s[i-2]) w=false;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                minlen=0x3f3f3f3f;
                v.clear();
                DFS(j,i,0,"");
                if((int)v.size()==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}