#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long cnt=0,n;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j =1;j<=a;j++)
        {
            s+=b;
        }
    }
    int k=s.size()/2;
    for(int i=0;i<=k;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
