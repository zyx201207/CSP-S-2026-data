#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int j=n;
    for(int i=1;i<=j;i++)
    {
        while(a[i]>0)
        {
            if(a[i]<a[j])
            {
                a[j]-=a[i];
                if(c[i]!=c[j])
                {
                    sum+=a[i];
                }
                a[i]=0;
            }
            else
            {
                a[i]-=a[j];
                if(c[i]!=c[j])
                {
                    sum+=a[j];
                }
                a[j]=0;
                j--;
            }
        }
    }
    cout<<sum;
    return 0;
}
