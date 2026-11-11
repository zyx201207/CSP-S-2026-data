#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,a[100005],tmpm;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        tmpm=m;
        if(a[i]<a[i+1])
        {
            if(a[i+1]-a[i]<m)
            {
                tmpm-=a[i+1]-a[i];
                a[i]=a[i+1];
                cnt++;
            }
            else
            {
                break;
            }
        }
        else if(a[i]==a[i+1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
