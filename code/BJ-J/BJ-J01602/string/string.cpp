#include<bits/stdc++.h>
using namespace std;

string st1,st2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans = 0,slen = 0;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j = 0;j<a;j++)
        {
            st1+=c;
            slen++;
        }
    }
    for(int i = 1;i<=slen;i++)
    {
        st2[slen-i] = st1[i-1];
    }
    int mid = slen/2;
    for(int i = 0;i<mid;i++)
    {
        if(st1[i] != st2[i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
