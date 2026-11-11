#include<bits/stdc++.h>
using namespace std;
int n;
char m[500000];
long long int a[500000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>m[i];
    }
    int i=1,j=n;
    long long cnt=0;
    while (j>i)
    {
        int p=a[i];
        int q=a[j];
        if(m[i] != m[j]) cnt+=min(a[i],a[j]);
        if(p>q)
        {
            a[i]-=a[j];
            j--;

        }
        else if(q>p)
        {
            a[j]-=a[i];
            i++;
        }
        else
        {
            i++;
            j--;
        }
    }
    cout<<cnt;
    return 0;
}
