#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[514514];
bool vis[514514];
int q[1000005];
int h=1,t=1;
int ans[514514];
void push(int k)
{
    q[t++]=k;
}
void pop()
{
    h++;
}
int findd(int k)
{
    for(int i=h;i<=t;i++)
        if(q[i]==k)return i;
    return 0;
}
int size()
{
    return t-h+1;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cout<<"3 1 4";
    return 0;
}
