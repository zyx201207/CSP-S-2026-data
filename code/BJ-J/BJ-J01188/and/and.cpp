#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long> cc;
long long cnt=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cc.push_back(-1);
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        cc.push_back(x);
    }
    for(int i=1; i<=n-m+1; i++)
    {
        int sum=cc[i];
        for(int k=0; k<=n-m-i+1; k++)
        {
            sum=cc[i];
            for(int j=i+1+k; j<=i+m-1+k; j++)
            {
                sum&=cc[j];
            }
            if(sum>cnt)
            {
                cnt=sum;
            }
        }

    }
    cout<<cnt;
    return 0;
}
