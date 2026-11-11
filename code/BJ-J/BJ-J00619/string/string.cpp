#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string s="";
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        for(long long j=1;j<=a;j++)
        {
            s+=b;
        }
    }
    long long i=0,j=s.size()-1,sum=0;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            sum++;
        }
        i++;j--;
    }
    cout<<sum;
    return 0;
}
