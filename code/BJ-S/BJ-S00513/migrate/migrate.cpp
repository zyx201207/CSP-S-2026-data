#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int len=d/(a[2]-a[1])*2;
        if(n-len+1<0) cout<<0<<endl;
        cout<<n-len+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

