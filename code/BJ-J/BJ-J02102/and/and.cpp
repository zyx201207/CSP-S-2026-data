#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],len,summ,ans=2147483647;
bool e[200005][35];
vector <long long> sum;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1,s,p;i<=n;i++)
    {
        cin>>a[i];
        s=a[i];
        p=0;
        while(s>0)
        {
            p++;
            e[i][p]=(s%2);
            s/=2;
            len=max(len,p);
        }
        sum.push_back(i);
    }
    for(long long i=len;i>=1;i--)
    {
        summ=0;
        for(long long j=1;j<=sum.size();j++)
        {
            if(sum[j-1]==-1)continue;
            if(e[j][i])summ++;
        }
        if(summ>=m)
        {
            for(long long j=1;j<=sum.size();j++)
            {
                if(sum[j-1]==-1)continue;
                if(!e[j][i])
                {
                    sum[j-1]=-1;
                }
            }
        }
    }
    for(long long i=1;i<=sum.size();i++)
    {
        if(sum[i-1]!=-1)ans=ans&a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
