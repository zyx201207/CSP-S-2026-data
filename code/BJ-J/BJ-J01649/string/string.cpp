#include <bits/stdc++.h>

using namespace std;
struct ing{
    long long a;
    char c;
}s[200010];
ing s1[200010];
long long cnt,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>s[i].a>>s[i].c;
        s1[n-i+1].a=s[i].a;
        s1[n-i+1].c=s[i].c;
        cnt+=s[i].a;
    }
    long long mid=cnt/2;
    long long last=0;
    char l;
    for(int i=1;i<=n;i++)
    {
        if(ans>mid)
        {
            cout <<mid;
            return 0;
        }
        /*if(s[i-1].c==l&&s[i-1].c<s[i].c&&i>1&&last!=0)
        {
            ans+=abs(min(s[i].a,s1[i].a)-last);
            last=0;
            if(abs(min(s[i].a,s1[i].a)-last)>0)
            {
                if(s[i].a>=s1[i].a)
                {
                    l=s[i].c;
                }
                else
                {
                    l=s1[i].c;
                }
                last=abs(s[i].a-s1[i].a);
                }
            }
        }
        if((s[i-1].c==l||s1[i-1].c==l)&&i>1&&last!=0)
        {
            ans+=abs(min(s[i].a,s1[i].a)-last);
            last=0;
            if(abs(min(s[i].a,s1[i].a)-last)>0)
            {
                if(s[i].a>=s1[i].a)
                {
                    l=s[i].c;
                }
                else
                {
                    l=s1[i].c;
                }
                last=abs(s[i].a-s1[i].a);
                }
            }
        }*/
        if(s[i].c!=s1[i].c)
        {
            ans+=min(s[i].a,s1[i].a);
            if(s[i].a>=s1[i].a)
            {
                l=s[i].c;
            }
            else
            {
                l=s1[i].c;
            }
            last=abs(s[i].a-s1[i].a);
        }
    }
    cout <<ans;
    return 0;
}
