#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int _,T;
int n;
long long d,a[2000005];
int f1[2000005];
int sum1[2000005];
int len1[2000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>_>>T;
    while(T--)
    {
        cin>>n>>d;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=false;
        }
        if(!flag)
        {
            int f[n+5][n+5];
            int sum[n+5][n+5];
            int len[n+5][n+5];
            memset(f,0,sizeof(f));
            memset(len,0x3f,sizeof(len));
            memset(sum,0x3f,sizeof(sum));
            for(int ln=2;ln<=n;ln++)
            {
                int l=2,r=1;
                for(int i=1;i+ln-1<=n;i++)
                {
                    while(r<n&&a[r+1]-a[i]<=d) r++;
                    int j=i+ln-1;
                    if(a[j]-a[i]<=d)
                    {
                        f[i][j]=1;
                        len[i][j]=1;
                    } 
                    else if(ln==2||r==i)
                        f[i][j]=0;
                    else
                    {
                        len[i][j]=len[r][j]+1;
                        while(l<r&&len[l][j]+1>len[i][j]) l++;
                        if(f[r][j]==0)
                            f[i][j]=0;
                        else
                        {
                            //f[l][j]~f[r][j]
                            f[i][j]=sum[l][j]-sum[r+1][j];
                            if(f[i][j]>2) f[i][j]=3;
                        }
                        // cout<<i<<" "<<j<<" l"<<l<<" r"<<r<<"\n";
                    }
                    sum[i][j]=f[i][j]+sum[i+1][j];
                }
            }
            long long cnt=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(f[i][j]==2) cnt++;
                    // cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<len[i][j]<<"\n";
                }
            }
            cout<<cnt<<"\n";
        }  
        else
        {
            for(int i=1;i<=n;i++)
                f1[i]=0,len1[i]=sum1[i]=0x3f3f3f3f;
                int r=1;
                while(r<n&&a[r+1]-a[1]<=d) r++;
            for(int ln=2;ln<=n;ln++)
            {
                int l=2;
                int i=1;
                int j=i+ln-1;
                if(a[j]-a[i]<=d)
                {
                    f1[ln]=1;
                    len1[ln]=1;
                } 
                else if(ln==2||r==i)
                    f1[ln]=0;
                else
                {
                    len1[ln]=len1[j-r+1]+1;
                    int l=1,p=r;
                    while(l<p)
                    {
                        int mid=l+p>>1;
                        if(len1[j-mid+1]+1>len1[ln])
                            l=mid+1;
                        else
                            p=mid;
                    }
                    // while(l<r&&len1[j-l+1]+1>len1[ln]) l++;
                    if(f1[j-r+1]==0)
                        f1[ln]=0;
                    else
                    {
                        //f[l][j]~f[r][j]
                        f1[ln]=sum1[j-l+1]-sum1[j-r];
                        if(f1[ln]>2) f1[ln]=3;
                    }
                    
                }
                sum1[ln]=f1[ln]+sum1[j-i];
                // cout<<l<<"\n";
            }
            long long cnt=0;
            for(int i=2;i<=n;i++)
            {
                if(f1[i]==2) cnt+=n-i+1;
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}