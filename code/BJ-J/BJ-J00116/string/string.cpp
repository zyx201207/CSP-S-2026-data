#include <bits/stdc++.h>
using namespace std;
int n,a;
char c;
long long cnt,maxx;
long long t[40];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>a>>c;
        cnt+=a;
        int i=c-'a';
        t[i]+=a;
    }
    for(int i=0;i<=40;i++)
        maxx=max(maxx,t[i]);
    if(cnt%2)
    {
        if(maxx==cnt) cout<<0;
        else cout<<cnt-maxx-1;
    }
    else cout<<cnt-maxx;
    return 0;
}
