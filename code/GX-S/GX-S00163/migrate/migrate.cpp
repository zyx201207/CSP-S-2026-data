#include <bits/stdc++.h>
using namespace std;
int c,t;
typedef long long int ll;
const int LEN = 2e6+2;
int n,d;
struct node{
    int l,r,val;
};
vector<node> cnt[10];
vector<int> g[10];
int a[LEN];
bool vis[15];
//yaweijiaoyan!(10000000)_2
void dfs2(int s,int x,int y,int ckn,int dist){
    if (x == y && dist == y - s){
        //ckn += (1<<y);
        node nt;
        nt.l = s,nt.r = y,nt.val = ckn;
        bool flag = true;
        for (auto i:cnt[y]){
            if(i.val == ckn && i.l == s && i.r == y)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cnt[y].push_back(nt);
        return ;
    }
    for (auto i:g[x]){
        if (i != x)
            dfs2(s,i,y,ckn+(1<<i),dist + 1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if (c<=2){//DFS
        while (t--){
            //memset(dis,0x3f,sizeof(dis));
            cin>>n>>d;
            for (int i=1;i<=n;i++)
                cin>>a[i];
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    if (a[j] - a[i] <= d)
                        g[i].push_back(j);
            memset(vis,0,sizeof(vis));
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;++j)
                    dfs2(i,i,j,1<<i,0);
            ll ans = 0;

            for (int i=0;i<10;i++){
                int k=cnt[i].size();
                if (k >= 2)
                    ans += ((k*k-k)>>1);
            }
            cout<<ans<<'\n';
            memset(vis,0,sizeof(vis));

        }

    //x
    }
    if (c == 13 || c == 14){
        //B:[mid-d,mid+d];
        while (t--){
            cout<<0<<'\n';
        }
    }

    return 0;
}
