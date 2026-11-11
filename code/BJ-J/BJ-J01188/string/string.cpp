#include<bits/stdc++.h>
using namespace std;
unsigned long long cnt,sum;
vector<char> v,fv;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char cc;
        cin>>x>>cc;
        for(int j=1;j<=x;j++)
            v.push_back(cc);
        sum+=x;
    }
    sum=(sum%2==1)?sum/2+1:sum/2;
    fv=v;
    reverse(fv.begin(),fv.end());
    if(fv==v){cout<<0;return 0;}
    for(long long i=0;i<sum;i++)
    {
        if(fv[i]!=v[i])cnt++;
        else continue;
    }
    cout<<cnt;
    return 0;
}
