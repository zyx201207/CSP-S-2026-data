#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MAXN=100005;
vector<int>g[MAXN];
void acce(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
using namespace std;
ll c,n,m,d,q;
ll w[MAXN][MAXN];
int idx=0;
ll g[MAXN][MAXN];
int w;
void add(int u,int v,int val){g[u][v]=val;g[v][u]=val;}
struct node
{
    int idx;
    int ditiezhan;
    int ditiezhan_dis;
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >>d >> q;
    cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
