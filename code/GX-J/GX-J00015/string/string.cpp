#include <bits/stdc++.h>
using namespace std;
long long n,a[1000005],sum;
char r;
string s;
long long wen(string s2)
{
    sum=0;
    for(long long i=0;i<s2.size();i+=2)
    {
        if(s2[i]!=s2[s2.size()-i-1])
            sum++;
    }
}
int main()
{
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>r;
        for(long long j=0;j<a[i];j++)
            s+=r;
    }
    wen(s);
    cout<<sum;
    return 0;
}

