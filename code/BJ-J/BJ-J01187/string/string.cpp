#include <bits/stdc++.h>
using namespace std;
struct ss
{
    long long s;
    char c;
}a[250000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long s;
        cin>>s;
        char c;
        cin>>c;
        a[i].s=s;
        a[i].c=c;
    }
    long long sum=0;
    int l=1,r=n;
    while(l<r)
    {
        if(a[l].c!=a[r].c)
        {
            sum+=min(a[l].s,a[r].s);
            //cout<<min(a[l].s,a[r].s)<<" "<<a[l].c<<"---"<<a[r].c<<endl;
        }
        if(a[l].s<a[r].s)
        {
            a[r].s-=a[l].s;
            l++;
        }
        else if(a[l].s>a[r].s)
        {
            a[l].s-=a[r].s;
            r--;
        }
        else if(a[l].s==a[r].s)
        {
            l++;
            r--;
        }

    }
    cout<<sum;
    return 0;
}
