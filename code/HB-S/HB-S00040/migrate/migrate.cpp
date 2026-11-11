#include<bits/stdc++.h>
using namespace std;
const int M=2e6+2;
int c,t,n,d,a[M],l=1,r=4,cnt,ans;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if((c==11||c==12)&&d>=(a[2]-a[1]))
        {
            if(n-3<0)
                cout<<0<<endl;
            else
                cout<<n-3<<endl;
        }
        else if((c==11||c==12)&&d<(a[2]-a[1]))
            cout<<0<<endl;
        else
        {
            if(n<4)
                cout<<0<<endl;
            else
            {
                while(r<=n&&(r-l)>=3)
                {
                    cnt=0;
                    for(int i=l+1;i<r;i++)
                    {
                        if((a[i]-a[l])<=d&&(a[r]-a[i])<=d)
                            cnt++;
                    }
                    if(cnt==2)
                        ans++;
                    else if(cnt>2)
                        l++;
                    else
                        r++;

                }
                cout<<ans;
            }
        }
    }

    return 0;
}

