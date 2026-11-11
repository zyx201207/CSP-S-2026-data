#include<bits/stdc++.h>
using namespace std;

int n,m;
const int maxN=2e5+10;
int a[maxN];
int B[maxN][40];
struct node
{
    int num;
    int shu;
}bi[maxN];

bool cmp(node x,node y)
{
    if(x.num==y.num)
        return x.shu>y.shu;
    return x.num>y.num;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int qn=0;
    for(int i=1;i<=n;i++)
    {
        int q=a[i],j=1;
        bi[i].shu=a[i];
        while(q)
        {
            B[i][j]= q&1;
            q=q>>1;
            j++;
            if(B[i][j]==1)
                bi[i].num++;
        }
        if(j-1>qn)
            qn=j-1;
    }
    sort(bi+1,bi+n+1,cmp);
    int ans=0x3f3f3f3f;
    for(int i=1;i<=m;i++)
        ans&=bi[i].shu;
    cout<<ans;
    return 0;
}
