#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int dfs(int x,int k,int mx)
{
    if(k==m) return mx;
    if(x>n) return 0;
    int r1,r2;
    if(k==0) {
        r1=dfs(x+1,k+1,a[k]);
        r2=dfs(x+1,k,mx);
    }
    else{
        r1=dfs(x+1,k+1,mx&a[k]);
        r2=dfs(x+1,k,mx);
    }
    return max(r1,r2);
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int y=1;y<=n;y++)
cin>>a[y];
cout<<dfs(0,0,0);
return 0;
}
