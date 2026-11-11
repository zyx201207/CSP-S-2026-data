#include<bits/stdc++.h>
using namespace std;
long long x;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;long long m;cin>>n>>m;
    vector<long long> v;
    for(int i=0;i<n;i++){cin>>x;v.push_back(x);}
    sort(v.begin(),v.end());
    vector<long long> cum;
    for(int i=0;i<n-1;i++)
    {
        cum.push_back(v[i+1]-v[i]);
    }
    long long sum=0,k=0;
    while(m>=0&&n>=0)
    {
        m-=cum[k];
        k++;
        sum++;
    }
    if(sum>=n)
    {

        sum=n;
    }
    cout<<sum;
    return 0;
}
