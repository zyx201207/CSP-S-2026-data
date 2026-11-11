#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000000],ans=0,ifone[1000000]={0};
int n,m,lens;

void change(long long q)
{
    lens=0;
    int qans=0;
    for(int ii=0;;ii++)
    {

        if(q%2==1)ifone[ii]++;
        qans=q%2;
        qans*=10;
        q/=2;
        lens++;
        if(q<=1)break;
    }

    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        change(a[i]);
    }
    cout<<ans;
    return 0;
}
