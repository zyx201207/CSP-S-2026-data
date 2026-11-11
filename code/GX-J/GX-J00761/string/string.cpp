#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
        cin>>b[i];
    }
    int check=n/2;
    for(int i=0;i<check;i++)
    {
        if(b[i]!=b[n-i])
        {

            if(a[i]<a[n-i])
            {

                b[i]=b[n-i];
                ans+=a[i];
            }
            else
            {

                b[n-i]=b[i];
                ans+=a[n-i];
            }

        }

    }
    cout<<ans;
    return 0;


}
