#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    char c;
}str[200005];
int main()
{
    ios::sync_with_stdio(false);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    unsigned long long n, ans=0, cnt=0;
    string st;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>str[i].a>>str[i].c;
        for(int j=0; j<str[i].a; j++)
        {
            st[cnt++]=str[i].c;
        }
    }
    //cout<<cnt<<endl;
    for(int i=0; i<cnt-i; i++)
    {
        //cout<<st[i]<<' '<<st[cnt-1-i]<<endl;
        if(st[i]!=st[cnt-1-i])
        {
            ans++;
        }

    }
    cout<<ans;
    return 0;
}
