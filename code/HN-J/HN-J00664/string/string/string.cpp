#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<char> s1;
int a;
char b;
ll tot;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int t=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s1.push_back(b);
            t++;
        }
    }
    t--;
    int p=0,q=t-1;
    while(p<=q)
    {
        if(s1[p]==s1[q])
        {
            p++;q--;
            continue;
        }
        p++;q--;
        tot++;
    }
    cout<<tot;
    return 0;
}
