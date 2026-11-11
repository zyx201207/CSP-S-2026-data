#include<bits/stdc++.h>
using namespace std;
int a[5000000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,cnt=0;
    long long m;
    cin>>n>>m;
    for(int i=1;i=m;i++)
    {
        a[i]+1;
        for(int j=1;j=m;j++)
        {
            if(a[i]=a[j])
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
