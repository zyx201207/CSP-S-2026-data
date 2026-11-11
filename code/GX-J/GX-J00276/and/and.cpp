#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=0,a[200010],cnt=0;
bool c[200010];
void dfs(int n,int l,int m,int b){
    if(l==m){
        maxn=max(maxn,b);
        return;
    }
    for(int i=0;i<n;i++){
        if(c[i]==true)continue;
        if(l==0)b=a[i];
        else b=b&a[i];
        c[i]=true;
        dfs(n,l+1,m,b);
        c[i]=false;
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(n,0,m,0);
    cout<<maxn<<endl;
    return 0;
}
