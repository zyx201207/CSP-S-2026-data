#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long l=0;
    cin>>n;
    string s=" ";
    for(int i=1;i<=n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(long long j=1;j<=a;j++)
        {
            s+=c;
        }
        l+=a;
    }
    long long cnt=0;
    for(long long i=1;i<=(l/2);i++)
    {
        if(s[i]!=s[l-1+1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}