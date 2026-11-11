#include <iostream>
using namespace std;
long long a[200005],a1[100005],b1[100005];
char b[200005],a2[100005],b2[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long c=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        c+=a[i];
    }
    int sum=0,c1=0,c2=0;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i];
        if(sum<=c/2)
        {
            c1++;
            a1[c1]=a[i],a2[c1]=b[i];
        }
        else if(sum-a[i]>=c/2)
        {
            c2++;
            b1[c2]=a[i],b2[c2]=b[i];
        }
        else{
            c1++;
            a1[c1]=c/2-a[i]+1ll,a2[c1]=b[i];
            c2++;
            b1[c2]=a[i]-c/2+1ll,b2[c2]=b[i];
        }
    }
    if(c%2==1)
    {
        b1[1]--;
    }
    /*for(int i=1; i<=c1; i++)
    {
        cout<<a1[i]<<" "<<a2[i]<<endl;
    }
    cout<<endl;
    for(int i=1; i<=c2; i++)
    {
        cout<<b1[i]<<" "<<b2[i]<<endl;
    }*/
    long long u=1;
    long long ans=0;
    for(int i=1; i<=c1; i++)
    {
        while(a1[i]>0)
        {
            if(b1[u]<=0)
            {
                u++;
            }
            if(a1[i]>=b1[u])
            {
                if(a2[i]!=b2[u])
                {
                    ans+=min(b1[u],a1[i]);
                }
                a1[i]-=b1[u];
                u++;
            }
            else
            {
                if(a2[i]!=b2[u])
                {
                    ans+=min(b1[u],a1[i]);
                }
                b1[u]-=a1[i];
                a1[i]=0ll;
                if(b1[u]<=0)
                {
                    u++;
                }
            }
            if(u>c2)
            {
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<ans;



    return 0;
}
