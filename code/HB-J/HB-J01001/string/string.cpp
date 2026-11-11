#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
 long long ans=0;
 long long sum=0;
 long long sum1=0;
int main()
{
    freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,j;
    string c="";
    cin>>n;
    j=n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i]>>b[i];
        sum1+=a[i];
    }
    long long i=1;
    while(sum<sum1/2)
    {


        if(a[i]==a[j])
        {
            sum+=a[i];
            if(b[i]!=b[j])
            {

                ans+=a[i];
            }
            j--;
        }
        else
        {
            long long a1=a[i];

            while(a1>=a[j])
            {   sum+=a[j];
                a1-=a[j];
                if(b[i]!=b[j])
                {
                    ans+=a[j];
                }
                j--;
            }
            if(b[i]!=b[j])
            {

                ans+=a1;
            }
            a[j]-=a1;
            sum+=a1;
        }
        i++;
    }
    cout<<ans;
    return 0;
}

