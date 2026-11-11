#include <bits/stdc++.h>
using namespace std;
vector<long long>a,b,c;
long long ans[1000010],n,m;
int x,i,j,maodian=0;

void put0(int x)
{
    for(int ix=0;ix<j;ix++)
        c.push_back(b[ix]);
    b.clear();
    for(int ix=0;ix<j;ix++)
    {
        b.push_back(c[ix]);
    }
    return;
}

bool findsinb(int xx)
{
    for(int iix=0;iix<b.size();iix++)
    {
        if(xx=b[iix])return 1;
    }
    return 0;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);}
    for(int i=0;i<n;i++){
        b.clear();
        for(int j=i;j<n;j++)
        {
            if(findsinb(a[j]))
            {
                maodian=a[j];
                put0(maodian);
            }
            b.push_back(a[j]);
        }
        for(int iii=0;iii<m;iii++)if(m==b[iii])ans[iii]++;

    }
    for(int i=0;i<m;i++)cout<<ans[i]<<' ';
    return 0;
}
