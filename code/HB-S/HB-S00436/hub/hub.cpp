#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1005;
int C,T;
int n,k;
vector<int>e[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        n/=2;
        n/=2;k/=2;
        cout<<(int)ceil((n-k)*1.0/2)+1<<'\n';
    }
    return 0;
}
/*
rp++
sto sto ccf orz orz
rp++

qiuqiule qwq
buyaobaoling awa
*/