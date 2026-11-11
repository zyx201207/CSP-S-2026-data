#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string hw;
    long long n,x,sum=0,num=0,left;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>a;
        sum+=x;
        for(long long j=1;j<=x;j++)
        {
            hw+=a;
        }
    }
    left=sum;
    for(long long right=1;right<=sum/2;right++)
    {
        if(hw[right]!=hw[left])
            num++;

        left--;


    }
    cout<<num;
    return 0;
}
