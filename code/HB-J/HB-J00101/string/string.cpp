#include<bits/stdc++.h>
using namespace std;
#define int long long
int a;
string m;
struct node
{
    int ai;
    char ci;
}d[200005];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>d[i].ai>>d[i].ci;
    }
    m="\0";
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<d[i].ai;j++)
        {
            m+=d[i].ci;
        }
    }

    int k=0;
    int n=1;
    int b=m;
    int length()-1;
    while(n<b)
    {
        if(m[n]!=m[b])
        {
            k++;
        }
        n++;
        b--;
    }
    cout<<k<<endl;
    return 0;
}

