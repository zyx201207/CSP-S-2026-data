#include<bits/stdc++.h>
using namespace std;
struct str{
    char c;
    long long num;
}a[200005],b[200005];
unsigned long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].c;
        b[n-i+1].num=a[i].num;
        b[n-i+1].c=a[i].c;
    }
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(a[i].num>0)
        {
            if(a[i].num>=b[j].num)
            {
                a[i].num-=b[j].num;
                if(a[i].c!=b[j].c)
                {
                    ans+=b[j].num;
                }
                j++;
            }
            else
            {
                b[j].num-=a[i].num;
                if(a[i].c!=b[j].c)
                {
                    ans+=a[i].num;
                }
                a[i].num=0;
            }
        }
    }
    cout<<ans/2;
    return 0;
}
