#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,a[500005]={0},b[500005]={0},c=1;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++)
    {
        b[i]=a[i-1]-a[i];
        if(b[i]<0)
        {
            b[i]*=-1;
        }
    }
    for(long long i=2;i<=n;i++)
    {
        m-=b[i]*(i-1);
        if(m<0)
        {
            break;
        }
        c++;
    }
    cout<<c;
    return 0;
}
