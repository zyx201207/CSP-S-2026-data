#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string b[200005];
void and1(long long x,int y)
{
    string s="";
    while(x!=0)
    {
        if(x%2==1)
        {
            s=s+"1";
        }
        else
        {
            s=s+"0";
        }
        x/=2;
    }
    while(s.size()<30)
    {
        s=s+"0";
    }
    b[y]=s;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        and1(a[i],i);
    }
    for(int i=29;i>=0;i--)
    {
        vector<int> c;
        for(int j=1;j<=n;j++)
        {
            if(b[j][i]=='1')
            {
                c.push_back(j);
            }
        }
        if(c.size()>=m)
        {
            long long d=pow(2,i);
            sum+=d;
            long long z=0;
            for(int j=1;j<=n;j++)
            {
                if(j!=c[z])
                {
                    b[j]="000000000000000000000000000000";
                }
                else
                {
                    z++;
                }
                if(z>=c.size())
                {
                    break;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
