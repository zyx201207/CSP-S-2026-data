#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<char> v;
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        char a;
        cin>>a;
        for(int i=1;i<=m;i++)
        {
            v.push_back(a);
        }
    }
    long long ans=0;


    if(s%2==0)
    {
        long long x=v.size()/2;

        for(long long i=0,j=v.size()-1;j>=x;i++,j--)
        {

            if(v[i]!=v[j])
            {
                ans++;
            }
        }
    }
    else
    {
        long long x=v.size()/2+1;
        for(long long i=0,j=v.size()-1;j>=x;i++,j--)
        {

            if(v[i]!=v[j])
            {
                ans++;
            }
        }
    }
    cout<<ans;
}
