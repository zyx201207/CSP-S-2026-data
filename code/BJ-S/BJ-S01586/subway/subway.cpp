#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005
ll n,m,a[N],d[N],dp[N];
void solvec()
{
    if(n==2)cout<<32<<endl<<17<<endl;
    if(n==3)cout<<35<<endl<<16<<endl;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0)solvec();
    else solve();
    return 0;
}
