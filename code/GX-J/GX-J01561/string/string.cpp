#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int u = 0;
    cin >> n;
    string x1;
    string x2;
    for(int i=0;i<=n;i++)
    {
        string s;
        int m;
        cin >> m >> s;
        for(int j=0;j<=m;j++){
            s*=m;
            s+=s;
            x1=s;
        }
    }
    if(x1[i]==x1[x1.size()]+1-i)
    {
        return 0;
    }
    else
    {
        x1[i]=x1[x1.size()];
        u++;
    }
    return 0;
}
