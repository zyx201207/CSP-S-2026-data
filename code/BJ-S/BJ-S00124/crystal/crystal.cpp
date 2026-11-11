#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long m2=m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    long long len;
    long long sy=0;
    for(int i=2;i<=n;i++)
    {
        m2-=(i-1)*(a[i]-a[i-1]);
        if(m2<0)
        {
            len=i-1;
            sy=m2+(i-1)*(a[i]-a[i-1]);
            break;
        }
        if(m2==0)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[i]!=a[j])
                {
                    len=j;

                    break;
                }

            }

        }
    }

    for(int i=len+1;i<n;i++)
    {
        int js=-((len-1)*a[i]-len*a[i-1]+a[i-len]);
        //cout<<len<<" "<<sy<<" "<<js<<endl;
        if(js+sy>=len*(a[i+1]-a[i]))
        {
            i++;
            len++;
            sy-=(len*(a[i+1]-a[i])-js);
        }
        else
        {
            sy+=js;
        }
        //cout<<len<<" "<<sy<<" "<<js<<endl;

    }
    cout<<len;
}
/*
JJJ love LYX
*/

