#include<bits/stdc++.h>
using namespace std;
int a[5001][5001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n>5000)
    {
        int a,b;
        cin>>a>>b;
        int x=(b-a);
        int c=0;
        int ans=1;
        for(int i=x;m>0;m-=i,i+=x)ans++;
        cout<<ans;
    }

    return 0;
}
