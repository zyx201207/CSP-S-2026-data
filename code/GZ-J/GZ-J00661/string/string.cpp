//GZ-J00661
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long

struct node
{
    char a;
    int s;
};
int len;
int n;
node s[200005];
int a[135];
int b[135];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].s>>s[i].a;
        len+=s[i].s;
    }
    int sum=0;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(!f)
        {
            if(sum+s[i].s>len/2)
            {
                a[s[i].a]+=len/2-sum;
                if(len%2!=0)
                    b[s[i].a]+=sum+s[i].s-len/2-1;
                else
                    b[s[i].a]+=sum+s[i].s-len/2;
                f=1;
            }
            else
                a[s[i].a]+=s[i].s;
            sum+=s[i].s;
        }
        else if(f)
            b[s[i].a]+=s[i].s;
    }
    int cnt=0;
    for(int i='a';i<='z';i++)
    {
        if(a[i]-b[i]>0)
            cnt+=a[i]-b[i];
    }
    printf("%lld",cnt);
    return 0;
}
