#include <bits/stdc++.h>
using namespace std;
long long n,m,p,q,cnt=0;
struct node
{
    int a;
    char c;
}x[200010],y[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    m=n;
    for(long long i=1;i<=n;i++)
    {
        cin>>x[i].a>>x[i].c;
        y[m].a=x[i].a;
        y[m].c=x[i].c;
        m--;
    }
    p=q=1;
    while(1)
    {
        if(x[p].a>y[q].a)
        {
            if(x[p].c!=y[q].c)
            {
                cnt+=y[q].a;
            }
            x[p].a-=y[q].a;
            q++;
        }
        else if(x[p].a<y[q].a)
        {
            if(x[p].c!=y[q].c)
            {
                cnt+=x[p].a;
            }
            y[q].a-=x[p].a;
            p++;
        }
        else if(x[p].a==y[q].a)
        {
            if(x[p].c!=y[q].c)
            {
                cnt+=x[p].a;
            }
            p++;
            q++;
        }
        if(p==n+1&&p==q)
        {
            break;
        }
    }
    cout<<cnt/2;
    return 0;
}
