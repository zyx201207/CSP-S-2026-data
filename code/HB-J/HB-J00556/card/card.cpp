#include <bits/stdc++.h>

using namespace std;

const int MAX=5*1e5+5;
bool ifu[MAX];
int have[MAX];
bool ifcout[MAX];
int a[MAX];
int ans[MAX];

void build(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        have[i]=0;
        ifu[i]=0;
        ifcout[i]=0;
    }
}

void change1(int x,int n)
{
    int i;
    for(i=x;i<=n;i++)
    {
        ifu[i]=1;
        have[a[i]]=0;
    }
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        build(n);
        int now=i;
        for(j=i;j<=n;j++)
        {
            if(have[a[j]])
            {
                change1(have[a[j]],j-1);
            }
            have[a[j]]=j;
        }
        for(j=i;j<=n;j++)
        {
            //cout<<i<<" "<<j<<" "<<ifu[a[j]]<<endl;
            if(!ifu[j]&&!ifcout[a[j]])
            {
                ans[a[j]]++;
                ifcout[a[j]]=1;
            }

        }
    }
    for(i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
