#include <bits/stdc++.h>
using namespace std;
long long n,m,st=0,mo;
vector<long long> data;
long long sum[3000002];
void Ge()
{
    vector<long long> ar;
    bool flag=true;
    for(long long i=0;i<mo;i++)
    {
        long long a=ar.size();
        if(flag)
        {
            flag=false;
            ar.push_back(data[i+st]);
            continue;
        }
        for(long long j=0;j<a;j++)
        {
            if(data[i+st]==ar[j])
            {
                for(long long p=1;p<a-j+1;p++)
                {
                    ar.pop_back();
                }
            }
        }
            ar.push_back(data[i+st]);
    }
    for(long long i=0;i<ar.size();i++)
    {
        sum[ar[i]]++;
    }
    return ;
}
int main()
{
    long long num;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>num;
        data.push_back(num);
    }
    mo=data.size();
    for(long long i=0;i<n;i++)
    {
        Ge();
        st++;
        mo--;
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<sum[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
