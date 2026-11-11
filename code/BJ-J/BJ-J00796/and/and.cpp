#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ss[200005],ans;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        ss[i]=a;

    }
    sort(ss+1,ss+n+1);
    ans=ss[n-1]&ss[n];
    for(int j=2;j<=m;j++){

        ans=ans&ss[n-j];
    }
    cout<<ans;
    return 0;
}
