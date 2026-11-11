#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string s;
long long sum=0;
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        char c;
        cin>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
        sum+=a;
    }
    long long i,j;
    if(sum%2==1) {
        i=(sum/2)-1;
        j=i+2;
    }
    else
    {
        j=(sum/2);
        i=j-1;

    }
    for(i,j;i>=0 && j<=sum-1;i--,j++)
    {
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans;
    return 0;
}

