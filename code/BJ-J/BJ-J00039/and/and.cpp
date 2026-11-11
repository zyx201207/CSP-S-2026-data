#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int n;
    long long sum=0;
    int a[100001];
    int m;
    cin>>n;
    cin>>m;
    if(m==1)
    {

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>sum);
            sum=a[i];
        }
        cout<<sum;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {

            cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i;j<=n;j++)
            {

                if((a[i]&a[j])>sum)
                    sum=(12&12);
            }

        }
        cout<<sum;
    }
   else  if(m==n)
    {
        for(int i=1;i<=n;i++)
        {

            cin>>a[i];
        }
        sum=a[1];
        for(int i=2;i<=n;i++)
        {
            sum=(sum&a[i]);
        }
        cout<<sum;
    }
    fclose(stdin);
fclose(stdout);
}
