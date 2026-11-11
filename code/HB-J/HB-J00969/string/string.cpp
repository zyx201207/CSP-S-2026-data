#include<bits/stdc++.h>
using namespace std;
vector<char>p;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=1;
    p.push_back(' ');
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;
        char a;
        cin>>x;
        cin>>a;
        for(int i=cnt;i<=cnt+x-1;++i)p.push_back(a);
        cnt+=x;
    }
    int sum=0;
    //cout<<cnt;
    for(int i=1;i<=cnt/2;++i)
    {
        if(p[i]!=p[cnt-i])sum++;
    }
    cout<<sum;
    return 0;
}
/*
3
2 a
2 b
1 c
*/
