#include<bits/stdc++.h>

using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
string s;
long long  n,ans,cc,ls;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        cc+=a[i];
    }
    for(int i=0,j=n-1;i<j;)
    {
        if(c[i]!=c[j])
        {
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                ans+=a[j];
                j--;
            }
            else
            {
                a[j]-=a[i];
                ans+=a[i];
                i++;
            }
        }
        else
        {
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                j--;
            }
            else
            {
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
