#include<bits/stdc++.h>
using namespace std;
struct node
{
    char c;
    long long sz;
}s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        s[i].sz=a;
        s[i].c=b;
    }
    long long ans=0;
    int l=1,r=n;
    while(l<r)
    {
        if(s[l ].sz==0)
            l++;
        if(s[r].sz==0)
            r--;
        long long j=min(s[l].sz,s[r].sz);
        s[l].sz-=j;
        s[r].sz-=j;
        if(s[l].c!=s[r].c)
            ans+=j;
    }
    cout<<ans;
    return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
