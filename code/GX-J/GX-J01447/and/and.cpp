#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,c;
long long an,t;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    long long a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=60;i>=0;i--)
    {
        t=an|(1LL<<i);
        c=0;
        for(j=0;j<n;j++)
        {
            if((a[j]&t)==t)
            {
                c++;
            }
        }
        if(c>=m)
        {
            an=t;
        }
    }
    cout<<an<<endl;
    return 0;
}
