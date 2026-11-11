#include<iostream>
using namespace std;
int n;
int a[200005];
char c[200005];
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int ifr=1,ind=n;
    while(1)
    {
        //cout<<ifr<<" "<<ind<<" "<<a[ifr]<<" "<<a[ind]<<" "<<ans<<endl;
        if(c[ifr]==c[ind])
        {
            if(a[ifr]>a[ind]) a[ifr]-=a[ind],ind--;
            else if(a[ifr]==a[ind]) ifr++,ind--;
            else if(a[ifr]<a[ind]) a[ind]-=a[ifr],ifr++;
            if(ifr==ind) break;
            continue;
        }
        if(a[ifr]>a[ind])
        {
            ans+=a[ind];
            a[ifr]-=a[ind];
            ind--;
        }
        else if(a[ifr]==a[ind])
        {
            ans+=a[ifr];
            ifr++,ind--;
        }
        else if(a[ifr]<a[ind])
        {
            ans+=a[ifr];
            a[ind]-=a[ifr];
            ifr++;
        }
        /*cout<<ifr<<" "<<ind<<" "<<ans<<endl;*/
        if(ifr>=ind) break;
    }
    cout<<ans;
}
