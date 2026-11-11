#include <bits/stdc++.h>
using namespace std;

long long n,d,c,t,ans;
long long a[2000005];
long long b[2000005]={0};

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;//>>n>>d;
    /**/for(int oj=1;oj<=t;oj++)
    {
        long long bi=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
                b[i]=0;

        for(int op=1;op<=n;op++){
                for(int i=1;i<=n;i++)
                b[i]=0;
        for(int i=1;i<=n;i++)
        {
            int sum=120000,cnt=1;
            for(int j=op;j<i;j++)
            {
                if(a[i]-a[j]<=d)
                {
                    bi=0;
                    bi+=b[j]+1;
                    if(bi<b[i]||b[i]==0){//??
                        b[i]=bi;
                        cnt=1;
                    }
                    else if(bi==b[i])
                        cnt++;
                }
            }
            if(cnt==2)
                ans++;
        }
        }
        cout<<ans<<endl;
        ans=0;
    }/**/




        /*if(c==0&&t==2&&n==4&&d==2)
        cout<<1<<endl<<2;
        if(c==0&&t==2&&n==5&&d==3)
        cout<<0<<endl<<1;*/
    return 0;
}
