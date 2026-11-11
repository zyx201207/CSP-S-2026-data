#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    char c;
}a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].c;
    }
    int l=1,r=n;
    while(l<r)
    {
        if(a[l].c!=a[r].c) ans+=min(a[l].num,a[r].num);
        if(a[l].num>a[r].num)
        {
            a[l].num-=a[r].num;
            r--;
        }
        else
        {
            a[r].num-=a[l].num;
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
