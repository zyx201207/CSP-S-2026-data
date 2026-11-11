#include<bits/stdc++.h>
using namespace std;
long long n,j,dj,ans;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i <= n;i++)
    {
        cin>>a[i]>>c[i];
    }
    j=1;
    dj=n;
    while(1)
    {
        if(c[j] != c[dj])
        {
            if(a[j] > a[dj])
            {
                ans+=a[dj];
                a[j]-=a[dj];
                dj--;
            }
            else if(a[j] < a[dj])
            {
                ans+=a[j];
                a[dj]-=a[j];
                j++;
            }
            else if(a[j] == a[dj])
            {
                ans+=a[j];
                dj--;
                j++;
            }
        }
        else if(c[j] == c[dj])
        {
            if(a[j] > a[dj])
            {
                a[j]-=a[dj];
                dj--;
            }
            else if(a[j] < a[dj])
            {
                a[dj]-=a[j];
                j++;
            }
            else if(a[j] == a[dj])
            {
                dj--;
                j++;
            }
        }
        if(dj <= j)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
