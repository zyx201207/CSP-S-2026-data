#include<bits/stdc++.h>
using namespace std;
int a[200001],M=-1,n,m;
void dfs(int now,int s,int c)
{
    if(now>n){
        if(c==m){
            M=max(M,s);
        }
        return;
    }
    if(c>m) return;
    int x=a[now];
    dfs(now+1,s&a[now],c+1);
    dfs(now+1,s,c);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==0){
        cout<<0;
        return 0;
    }
    if(n<=2000){
        dfs(1,pow(2,31)-1,0);
        cout<<M;
    }
    else{
        int m=-1;
        for(int i=1;i<=n;i++){
            m=max(m,a[i]);
        }
        cout<<m;
    }
    return 0;
}
