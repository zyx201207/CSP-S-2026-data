#include<bits/stdc++.h>
using namespace std;
char c[100000010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int sum=0;
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        int x;char c1;
        cin>>x>>c1;
        sum+=x;
        for(;cnt<=sum;cnt++)
        {
            c[cnt]=c1;
        }
    }
    /*for(int i=1;i<=sum;i++)
    {
        cout<<c[i];
    }
    cout<<endl;*/
    int ans=0;
    for(int i=1;i<=sum/2;i++)
    {
        if(c[i]!=c[sum-i+1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
