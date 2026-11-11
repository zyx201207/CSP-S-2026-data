#include <bits/stdc++.h>
using namespace std;
int n;
int m;
char a;
string s,g;
char p[200005];
int qp[200005];
long long sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        sum+=m;
        qp[i]=m;
        cin>>a;
        p[i]=a;
        for(int j=1;j<=m;j++)
        {
            s+=a;
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=qp[i];j++)
        {
            g+=p[i];
        }
    }
    long long cnt=0;
    for(int i=0;i<sum;i++)
    {
        if(s[i]!=g[i])
        {
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
