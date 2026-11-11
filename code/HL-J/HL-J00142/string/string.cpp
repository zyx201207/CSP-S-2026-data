#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string x;
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int y;
        char l;
        cin>>y>>l;
        for(int i=m;i<=y;i++)
        {
            x[i]=l;
        }
        m+=y;
    }
    int cnt=0;
    for(int i=0;i<=m/2-1;i++)
    {
        if(x[i]!=x[m-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
