#include<bits/stdc++.h>
using namespace std;
int n,a;
string b,s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s=s+b;
        }
    }
    int mid=0;
    if((s.size())%2==0)
    {
        mid=1;
    }
    else
    {
        mid=s.size()/2+1;
    }
    s=" "+s;
    int cnt=0;
    int len=s.size();
    for(int i=1;i<=mid;i++)
    {
        if(s[i]!=s[len-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
