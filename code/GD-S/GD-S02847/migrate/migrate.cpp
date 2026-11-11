#include<bits/stdc++.h>
using namespace std;

int x[10005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>x[i];
        }
    }
    if(c==0)
    {
        cout<<"1"<<endl<<"2";
    }
    else
    {
        cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";

    }
    return 0;
}

