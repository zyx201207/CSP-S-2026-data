#include<bits/stdc++.h>
using namespace std;
bool a[200005][35];
bool ans2[35];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int lmax=-9178;
    for(int i=1;i<=n;i++)
    {
        int l;
        cin>>l;
        a[i][0]=1;
        lmax=max(int(log2(l))+1,lmax);
        int j=1;
        while(l)
        {
            a[i][j]=l%2;
            l/=2;
            j++;
            //cout<<l<<endl;
        }
    }

    for(int i=lmax;i>=1;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][0]==0)
            {
                continue;
            }
            cnt+=int(a[j][i]);
            //cout<<i<<" "<<j<<" "<<cnt<<endl;
        }
        if(cnt>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j][i]==0)
                {
                    //cout<<1;
                    a[j][0]=0;
                }
            }
            ans2[i]=1;
        }
    }
    int ans=0;
    for(int i=lmax;i>=1;i--)
    {
        ans*=2;
        ans+=ans2[i];
    }
    cout<<ans<<endl;
    return 0;
}
