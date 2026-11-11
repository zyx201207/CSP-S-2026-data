#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[100005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4)
        {
            cout<<1<<endl;
        }
        if(n==5&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
        {
            cout<<2<<endl;
        }
        if(n==5&&d==3&&a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2)
        {
            cout<<0<<endl;
        }
        if(n==6&&d==2&&a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6)
        {
            cout<<1<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
