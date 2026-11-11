#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    unsigned long long len=0,cnt=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        len+=x;
        for(int i=1;i<=x;i++)s+=c;
    }
    for(int i=1;i<=len/2;i++)
    {
        if(s[i]!=s[len/2+i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
