#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
int q[MAXN];
int top;
int n,m;
int a[MAXN];
bool exist[MAXN];
int where[MAXN];
int ans[MAXN];
void cha() {for(int i=1;i<=m;i++) if(exist[i]) ans[i]++;}
void del(int n)
{
    for(int i=n;i<=top;i++) exist[q[i]]=false;
    top=n-1;
}
void chu(int n)
{
    if(exist[n]) del(where[n]);
    q[++top]=n;
    where[n]=top;
    exist[n]=true;
    cha();
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(q,0,sizeof(q));
        memset(where,0,sizeof(where));
        memset(ans,0,sizeof(ans));
        for(int j=0;j<MAXN;j++) exist[i]=false;
        for(int j=i;j<=n;j++)
        {
            chu(a[j]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[m]<<" ";
    }
    cout<<endl;
    return 0;
}
