
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int m=0;
        char c;
        cin>>m>>c;
        while(m--)
            s+=c;
    }
    long long sum=0;
    long long len=s.size();
    for(long long i=0;i<(len/2);++i)
    {
        if(s[i]!=s[len-i-1]) sum++;
    }
    cout<<sum;
    return 0;
}

