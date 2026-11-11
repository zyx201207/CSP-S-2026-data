#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll read()
{
    ll res=0;
    ll tmp=1;
    char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
    if(ch=='-') tmp=-1,ch=getchar();
    while(ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*tmp;
}
vector<int> e[1000010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cout<<n-1<<'n';
    }
    return 0;
}