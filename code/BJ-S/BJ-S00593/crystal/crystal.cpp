#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[500005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int maxans=0;
    for(int i=2;i<n;i++)
    {
        int temp=0,t=1,tempm=m;
        for(int j=i-1;j>0;j--)
        {
            if(tempm>=(a[i]-a[j]))
            {
                tempm-=(a[i]-a[j]);
                temp++;
            }
            else
            {
                break;
            }
        }
        maxans=max(maxans,temp+1);
    }
    cout<<maxans;
    return 0;
}
