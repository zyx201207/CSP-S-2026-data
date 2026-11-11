#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int maxand=-1e8;
void dfs(int sum, int idx, int dep)
{
    if(dep==m){
        maxand=max(maxand, sum);
        return ;
    }
    for(int i=idx+1;i<=n;i++){
        dfs((sum & a[i]), i, dep+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(a[i], i, 1);
    }
    cout<<maxand;
    return 0;
}
