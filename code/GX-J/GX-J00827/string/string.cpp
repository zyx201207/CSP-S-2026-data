#include<bits/stdc++.h>
using namespace std;
string a{1000010};
string b{1000010};
string c{1000010];
int main()
{
    freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     int n,ai;
     char ci;
     cin>>n>>ci>>ai;
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=ai;i++)
        {
            a[1000010]+=ci;
        }
     }
     int cnt=0,cnt2=0;
     for(int i=1;i<=a.size();i++)
     {
        if(a[i]!=a[i+1])
        {
            for(int j=i;j<=a.size();j++)
            {
                if(a[j]==a[j+1])
                {
                    cnt2++;
                }
                if(a[j]!=a[j+1])
                {
                    int x=i/j;
                    break;
                }
            }

        }

       }        for(int k=a.size();k>=x;k++)
                {
                    b+=k;
                    for(int i=1;i<=x;i++)
                    {
                        c+=i
                          if(b.size()>c.size()||b.size<c.size)
                            {


                                b.size=c.size;
                                cnt++;
                            }


                for(int k=a.size();k>=x;k++)
                {
                    for(int i=1;i<=x;i++)
                    {

                        if(c[i]!=b[k])
                        {
                            b[k]=c[i];
                            cnt++;
                        }
                    }


                }




            }
        }
        cout<<cnt;
    return 0;
}
