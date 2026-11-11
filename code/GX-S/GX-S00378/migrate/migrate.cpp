#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
long long c,t,n,d,a[10000000],sl=0,sl1=0;
cin>>c>>t;
for(long long i=1;i<=t;i++)
{
    cin>>n>>d;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=d;i++)
      {


        if(a[1+i*i]==a[0+n])
    {
      sl++;
    }
    else
        {
            if(sl>2)
            {
                if(sl/2==0)
                {
                cout<<sl%2;
                }

            }
            else{
                if(sl=2)
                {
                cout<<'1';
                }
                else
                    {
                    if(sl<2)
                    {
                    cout<<'0';
                    }
                    else
                    {
                        if(sl/2==0)
                {
                cout<<sl%2;
                    }
                }
            }
        }
      }
      }
}
for(long long i=1;i<=t;i++)
{
    cin>>n>>d;
    for(long long i=1;i<=d;i++)
    {
                    cin>>a[i];


    if(a[1+i*i]==a[0+n])
    {
       sl1++;
    }
    else
        {
            if(sl1>2)
            {
                if(sl1/2==0)
                {
                cout<<sl1%2;
                }

            }
            else{
                if(sl1=2)
                {
                cout<<'1';
                }
                else{
                   if(sl1<2)
                    {
                    cout<<'0';
                    }
                    else{
                        if(sl1/3==0)
                        {
                            cout<<(sl1-1)%2;
                        }
                    }
                }
            }
        }
    }
}
return 0;
}
