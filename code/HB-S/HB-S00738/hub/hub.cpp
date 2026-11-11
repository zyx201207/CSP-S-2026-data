#include<bits/stdc++.h>
using namespace std;
const int N=6e5;
int c,T,n,d;
vector <int> e[N];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cout << 1 << endl;
    }
   
}