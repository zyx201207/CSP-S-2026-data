#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    long long ans=a[1];
    long long maxn=-1;
    if(n<=20)
    {
        int t;
        int maxx=-1;
        if(n==1)
        {
            if(m==1) cout<<a[1];
        }
        else if(n==2)
        {
            if(m==1) cout<<a[1];
            else
            {
                t=a[1]&a[2];
                cout<<t;
            }
        }
        else if(n==3)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                int t=a[1]&a[2]&a[3];
                cout<<t;
            }
        }
        else if(n==4)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4];
                cout<<t;
            }
        }
        else if(n==5)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5];
                cout<<t;
            }
        }
        else if(n==6)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6];
                cout<<t;
            }
        }
        else if(n==7)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7];
                cout<<t;
            }
        }
        else if(n==8)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8];
                cout<<t;
            }
        }
        else if(n==9)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9];
                cout<<t;
            }
        }
        else if(n==10)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10];
                cout<<t;
            }
        }
        else if(n==11)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11];
                cout<<t;
            }
        }
        else if(n==12)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12];
                cout<<t;
            }
        }
        else if(n==13)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13];
                cout<<t;
            }
        }
        else if(n==14)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==13)
            {
                for(int i=1;i<=n-12;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13]&a[14];
                cout<<t;
            }
        }
        else if(n==15)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==13)
            {
                for(int i=1;i<=n-12;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==14)
            {
                for(int i=1;i<=n-13;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13]&a[14]&a[15];
                cout<<t;
            }
        }
        else if(n==16)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==13)
            {
                for(int i=1;i<=n-12;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==14)
            {
                for(int i=1;i<=n-13;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==15)
            {
                for(int i=1;i<=n-14;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13]&a[14]&a[15]&a[16];
                cout<<t;
            }
        }
        else if(n==17)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==13)
            {
                for(int i=1;i<=n-12;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==14)
            {
                for(int i=1;i<=n-13;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==15)
            {
                for(int i=1;i<=n-14;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==16)
            {
                for(int i=1;i<=n-15;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13]&a[14]&a[15]&a[16]&&a[17];
                cout<<t;
            }
        }
        else if(n==18)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==13)
            {
                for(int i=1;i<=n-12;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==14)
            {
                for(int i=1;i<=n-13;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==15)
            {
                for(int i=1;i<=n-14;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==16)
            {
                for(int i=1;i<=n-15;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==17)
            {
                for(int i=1;i<=n-16;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15]&&a[i+16];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13]&a[14]&a[15]&a[16]&&a[17]&a[18];
                cout<<t;
            }
        }
        else if(n==19)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==13)
            {
                for(int i=1;i<=n-12;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==14)
            {
                for(int i=1;i<=n-13;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==15)
            {
                for(int i=1;i<=n-14;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==16)
            {
                for(int i=1;i<=n-15;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==17)
            {
                for(int i=1;i<=n-16;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15]&&a[i+16];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==18)
            {
                for(int i=1;i<=n-17;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15]&&a[i+16]&&a[i+17];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13]&a[14]&a[15]&a[16]&&a[17]&a[18]&&a[19];
                cout<<t;
            }
        }
        else if(n==20)
        {
            if(m==1) cout<<a[1];
            else if(m==2)
            {
                for(int i=1;i<=n-1;i++)
                {
                    t=a[i]&a[i+1];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==3)
            {
                for(int i=1;i<=n-2;i++)
                {
                    t=a[i]&a[i+1]&a[i+2];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==4)
            {
                for(int i=1;i<=n-3;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==5)
            {
                for(int i=1;i<=n-4;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==6)
            {
                for(int i=1;i<=n-5;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==7)
            {
                for(int i=1;i<=n-6;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==8)
            {
                for(int i=1;i<=n-7;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==9)
            {
                for(int i=1;i<=n-8;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==10)
            {
                for(int i=1;i<=n-9;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==11)
            {
                for(int i=1;i<=n-10;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==12)
            {
                for(int i=1;i<=n-11;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==13)
            {
                for(int i=1;i<=n-12;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==14)
            {
                for(int i=1;i<=n-13;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==15)
            {
                for(int i=1;i<=n-14;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==16)
            {
                for(int i=1;i<=n-15;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==17)
            {
                for(int i=1;i<=n-16;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15]&&a[i+16];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==18)
            {
                for(int i=1;i<=n-17;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15]&&a[i+16]&&a[i+17];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else if(m==19)
            {
                for(int i=1;i<=n-18;i++)
                {
                    t=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+6]&a[i+7]&a[i+8]&a[i+9]&a[i+10]&a[i+11]&a[i+12]&a[i+13]&&a[i+14]&&a[i+15]&&a[i+16]&&a[i+17]&&a[i+18];
                    maxx=max(maxx,t);
                }
                cout<<maxx;
            }
            else
            {
                t=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7]&a[8]&a[9]&a[10]&a[11]&a[12]&a[13]&a[14]&a[15]&a[16]&&a[17]&a[18]&&a[19]&&a[20];
                cout<<t;
            }
        }
    }
    else{
        if(m==1) cout<<ans;
        else if(m==n)
        {
            for(int i=2;i<=m;i++)
            {
                ans&=a[i];
            }
            cout<<ans;
        }
        else if(m==2)
        {
            for(int i=1;i<=n-1;i++)
            {
                ans=a[i]&a[i+1];
                maxn=max(maxn,ans);
            }
            cout<<maxn;
        }
    }
    return 0;
}
