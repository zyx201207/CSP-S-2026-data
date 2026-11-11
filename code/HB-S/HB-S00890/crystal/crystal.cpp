#include<bits/stdc++.h>
using namespace std;
int a[100009];
int b[100009];
int c[100009];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
     int n,m,mm,nn;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=1;

    }
    sort(a,a+n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        mm=m;
        nn=n;
        int j=i;
        int cnt=1;
        for(int f=1;f<=nn;f++)
        {
            int x=1;
            if(mm>=(a[j+1]-a[j])*x&&c[j+1]==1)
            {
                cnt+=x;
                mm-=(a[j+1]-a[j])*x;
            }
            else
            {
                mm=0;
            }
             cout<<mm<<" "<<a[j]<<" "<<a[j+1]<<" "<<cnt<<endl;
           j+=1;
           x+=1;

            if(mm==0)
            {
                nn=0;
            }

        }
        cout<<endl;
        b[i]=cnt;


    }
    for(int i=1;i<=n;i++)
    {
        if(sum<=b[i])
        {
            sum=b[i];
        }
    }
    cout<<sum;
    return 0;
}
