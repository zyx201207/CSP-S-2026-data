#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<long long> v(n+1);
    vector<long long> l(m+1);
    vector<long long> z(n+1);
    v.push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(l[a]!=0)
        {
            for(int j=v.size();j>=v.size()-z[a];j--)
            {
                l[v[j]]=0;
                z[v[j]]=0;
            }
            v.erase(v.begin()+z[a],v.end());
            z[a]=0;
            l[a]=0;
        }
        else
        {
            z[a]++;
            for(int j=1;j<=n;j++)
            {
                if(z[j]>0) z[j]++;
            }
            z[a]--;
        }
        l[a]++;
        for(int j=1;j<=m;j++)
        {
            if(l[j]>0) b[j]++;
        }
        v.push_back(a);
    }
    for(int j=1;j<=m;j++)
    {
        cout<<b[j]<<" ";
    }
    return 0;
}
