#include <bits/stdc++.h>
using namespace std;

int n,m,a,z=0,r=0;
string nl,ml,s,x,k;
int main()
{

    freopen("card.in","r",stdin); 
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>nl[i];
        if(x.find(nl[i])==0)
        {
            x[z]=nl[i];
            z++;
        }
        if(ml.find(nl[i])==0)
        {
            ml[i]=nl[i];
        }
        else
        {
            a=ml.find(nl[i]);
            for(int j=a+1;j<i;j++)
            {
                ml[j]=0;
            }
        }
        int y=ml.size();
        for(int i=0;i<z;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(ml[j]==x[i])
                {
                    s[i]++;
                }
            }
        }
        for(int i=0;i<z;i++)
        {
            if(s[i]!=0)
            {
              cout<<s[i];
            }
        }
    }
    return 0;
    }
