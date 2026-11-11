#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long m,n,da,mane;
    bool flag=true;
    vector<long long> data;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>da;
        data.push_back(da);
    }
    sort(data.begin(),data.end());
    for(long long i=1;i<n;i++)
    {
        long long cm=m,mena=1;
        for(long long j=i-1;j>=0;j--)
        {
            long long ne=data[i]-data[j];
            if(ne<=cm)
            {
                cm-=ne;
                mena++;
            }else
            {
                break;
            }
        }
        if(flag)
        {
            flag=false;
            mane=mena;
            continue;
        }
        mane=max(mane,mena);
    }
        cout<<mane;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
