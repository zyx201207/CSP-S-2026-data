#include<bits/stdc++.h>
using namespace std;
string a[200005];
int x[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string v={};
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>a[i];
        for(int j=1;j<=x[i];j++)
        {
            v+=a[i];
        }
    }
    int sum=0;
    int len=v.size();
    for(int i=0;i<len/2;i++)
    {
        if(v[i]!=v[len-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
