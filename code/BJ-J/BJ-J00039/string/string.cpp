#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    long long a[200001],c[200001] ,n;
    long long  w=1,q=1,k=1,l=1,ans=0,sum=0,h=0;
    char b[200001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i]>>b[i];
        sum+=a[i];
        c[i]=sum;

    }

    for(int i=n;i>=n/2;i--)
    {

        h+=a[i];
        c[i]=h;
    }
    for(int i=1;i<=sum/2;i++)
    {
        if(i>c[w])
        {
          w++;
          l++;

        }
        if(i>c[n-k+1])
        {

            k++;
            q++;
        }

        if(b[l]!=b[n-q+1])
            ans++;

    }
    cout<<ans;
    fclose(stdin);
fclose(stdout);
}