#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char c;
}s[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
    }
    int lefti=1,righti=n;
    long long ans=0;
    while(lefti<righti)
    {
        long long minn=min(s[lefti].a,s[righti].a);
        if(s[lefti].c==s[righti].c)
        {
            s[lefti].a-=minn;
            s[righti].a-=minn;
            if(s[lefti].a==0)
            {
                lefti++;
            }
            if(s[righti].a==0)
            {
                righti--;
            }
        }
        else
        {
            s[lefti].a-=minn;
            s[righti].a-=minn;
            ans+=minn;
            if(s[lefti].a==0)
            {
                lefti++;
            }
            if(s[righti].a==0)
            {
                righti--;
            }
        }
    }
    cout<<ans;
}