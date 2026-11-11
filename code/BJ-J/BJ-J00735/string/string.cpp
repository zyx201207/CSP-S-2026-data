#include <iostream>
using namespace std;

struct Str
{
    long long a;
    char c;
} f[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>f[i].a>>f[i].c;
    }

    int l=1,r=n;
    long long cntl=f[1].a;
    long long cntr=f[n].a;
    long long ans=0;
    long long lastcnt=0;
    while(l<=r)
    {
        long long cnt=min(cntl,cntr);

        if(f[l].c!=f[r].c)
        {
            int change=cnt-lastcnt;
            ans+=change;
        }

        if(cntl<cntr)
        {
            l++;
            cntl+=f[l].a;
        }
        else if(cntl>cntr)
        {
            r--;
            cntr+=f[r].a;
        }
        else
        {
            if(l+2==r)break;
            else
            {
                l++;
                cntl+=f[l].a;
                r--;
                cntr+=f[r].a;
            }
        }

        lastcnt=cnt;
    }

    cout<<ans<<endl;
    return 0;
}
