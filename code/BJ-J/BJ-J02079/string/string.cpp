#include <bits/stdc++.h>
using namespace std;

long long n,L,cnt;
string S=" ";

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;string y;
        cin>>x>>y;
        L+=x;
        for(int j=1;j<=x;j++)
            S+=y;
    }
    for(int i=1;i<=L/2;i++)
    {
        if(S[i]!=S[L+1-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
