#include<bits/stdc++.h>
#define int long long
#define cint const int
using namespace std;
int sum=0,ans=0;
cint N=2e5+10;
struct node
{
    char s;
    int num;
}a[N];
int n;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].s;
        sum+=a[i].num;
        //cout<<a[i].num;
    }
    //cout<<sum<<endl;
    int l=1,r=n;
    while(sum>1)
    {
        //cout<<sum<<endl;
        if(a[l].s!=a[r].s)
        {
            ans+=min(a[l].num,a[r].num);
        }
        if(a[l].num>a[r].num)
        {
            a[l].num-=a[r].num;
            //a[r].num=0;
            sum-=2*a[r].num;
            r--;
        }
        else if(a[l].num<a[r].num)
        {
            a[r].num-=a[l].num;
            //a[l].num=0;
            sum-=2*a[l].num;
            l++;
        }
        else
        {
            sum-=2*a[l].num;
            l++,r--;
        }
    }
    cout<<ans;
    return 0;
}

