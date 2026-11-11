#include<bits/stdc++.h>
using namespace std;
long long n,d,x[100010],sum[1010][1010];
long long dis(long long l,long long r)
{
    long long num=0,h=l;
    while(h<r)
    {
        long long y=h;
        while(x[y]-x[h]<=d&&y<=n)
        {
            //cout<<y<<"#"<<h<<"#"<<r<<endl;
            y++;
        }
        y--;
        num++;
        h=y;
        if(h<r&&x[h+1]-x[h]>d)
        {
            return -1;
        }
    }
    return num;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>d;
        for(long long i=1; i<=n; i++)
        {
            cin>>x[i];
        }
        for(int i=1; i<n; i++)
        {
            if(x[i+1]-x[i]<=d)
            {
                sum[i][i+1]=1;
                //cout<<i<<" "<<i+1<<" "<<sum[i][i+1]<<endl;
            }
        }
        for(int i=1; i<n-1; i++)
        {
            if(i==1)
            {
                //cout<<x[i+2]<<"#"<<x[i]<<endl;
            }
            if(sum[i][i+1]==1&&sum[i+1][i+2]==1)
            {
                sum[i][i+2]=1;
                //cout<<i<<"@"<<i+2<<" "<<sum[i][i+2]<<endl;
            }
        }
        for(long long len=3; len<=n; len++)
        {
            for(long long i=1; i+len<=n; i++)
            {
                long long j=i+len;
                long long x=dis(i,j),num=0;
                //cout<<i<<"**"<<j<<" "<<dis(i,j)<<endl;
                if(x==-1)
                {
                    break;
                }
                //cout<<x<<"#"<<endl;
                if(dis(i,j)==1)
                {
                    num=1;
                }
                for(long long k=i+1; k<j; k++)
                {
                    if(dis(i,k)+dis(k,j)==x)
                    {
                        num+=sum[i][k]*sum[k][j];
                        //cout<<i<<" "<<j<<" "<<k<<" "<<sum[i][k]<<"*"<<sum[k][j]<<endl;
                    }
                }
                if(num==2)
                {
                    ans++;
                }
                sum[i][j]=num;
                //cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
            }
        }
        cout<<ans<<endl;
    }
}
