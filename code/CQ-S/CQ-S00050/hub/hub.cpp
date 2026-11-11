#include<iostream>//在直径的中间分开,然后在2边分别bfs算出两边用i个的答案,然后枚举2边的使用个数.But I have no time!.
#include<cstdio>
#include<vector>
using namespace std;
vector<int>p[2000001];
int ff,ss;
void find(int x)
{

}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            p[u].push_back(v);
            p[v].push_back(u);
        }
    }
    return 0;
}
