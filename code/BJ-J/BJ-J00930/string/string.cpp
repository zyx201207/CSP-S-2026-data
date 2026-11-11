#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010

ll n,ans=0,l=0;
ll k[N],fk[N];
char c[N],fc[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>k[i]>>c[i];
        l+=k[i];
    }

    for(ll i=1;i<=n;i++)
    {
        fk[i]=k[n-i+1];
        fc[i]=c[n-i+1];
    }

    for(ll i=1,j=1;i<=n&&j<=n;)
    {
        //cout<<ans<< " : "<<k[i]<< " "<<c[i]<< " "<<fk[j]<< " "<<fc[j]<< "\n";
        if(c[i]==fc[j])
        {
            if(k[i]<fk[j])
            {
                fk[j]-=k[i];
                i++;
            }
            else if(k[i]>fk[j])
            {
                k[i]-=fk[j];
                j++;
            }
            else i++,j++;
        }
        else
        {
            if(k[i]<fk[j])
            {
                ans+=k[i];
                fk[j]-=k[i];
                i++;
            }
            else if(k[i]>fk[j])
            {
                ans+=fk[j];
                k[i]-=fk[j];
                j++;
            }
            else
            {
                ans+=k[i];
                i++,j++;
            }
        }
    }

    cout<<ans/2<< "\n";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
