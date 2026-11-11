#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,cnt=0;
    long long sum=0;
    string c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        sum+=a;
        for(int j=1;j<=a;j++)
        {
            s=s+c;
        }
    }
    for(int i=0;i<sum/2;i++)
    {
        if(s[i]!=s[sum-1-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
