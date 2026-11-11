#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,l,s;
long long a[2000005],b[2000005];
long long ans,sta,cnt,lin;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if((c==11)||(c==12))
    {
        for(int r=0;r<t;r++)
        {
            cin>>n>>d;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            l=a[1]-a[0];
            if(n==1)
            {
                ans=0;
                cout<<0<<endl;
            }
            else if(d<=l)
            {
                ans=0;
                cout<<0<<endl;
            }
            else
            {
                s=d/l;
                if((n-1)<=s)
                {
                    ans=0;
                }
                sta=2*s;
                ans=n-sta+1;
                if(ans<0)
                {
                    ans=0;
                }
                //cout<<l<<" "<<d<<" "<<s<<" "<<sta<<endl;
                cout<<ans<<endl;
            }
        }
    }
    else
    {
        for(int r=0;r<t;r++)
        {
            cnt=0;
            cin>>n>>d;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            l=a[1]-a[0];
            if(d==1)
            {
                cout<<0<<endl;
            }
            else
            {
                for(int i=1;i<n;i++)
                {
                    b[i]=a[i]-a[i-1];
                }
                if((b[1]+b[2]+b[3])==2*d-1)
                {
                    cnt++;
                }
            }
            ans=cnt;
            cout<<ans<<endl;

        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
