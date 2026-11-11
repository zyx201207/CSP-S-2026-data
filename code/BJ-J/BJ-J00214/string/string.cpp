#include<bits/stdc++.h>
using namespace std;
int n, cnt=0,  a[1000000];
string s[1000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        cin >> s[i];
    }
    for(int i = 2;i<=n;i++)
    {
        if(s[i]==s[i-1])
            cnt++;
    }
    if(cnt==n-1)
        cout<<0;
    return 0;
}