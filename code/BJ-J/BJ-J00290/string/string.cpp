#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int m=(n+1)/2,j=1,k=n+1-j;
    while(j<=m&&k>=m)
    {
        if(c[j]==c[k])
        {
            if(a[j]>a[k]) a[j]-=a[k],k=n-j;
            else if(a[j]<a[k]) a[k]-=a[j],j++;
            else j++,k=n-j+1;
        }
        else
        {
            if(a[j]>a[k])
            {
                cnt+=a[k];
                a[j]-=a[k],k=n-j;
            }
            else if(a[j]<a[k])
            {
                cnt+=a[j];
                a[k]-=a[j],j++;
            }
            else
            {
                cnt+=a[j];
                j++,k=n-j+1;
            }
        }
    }
    cout<<cnt;
}
