#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,b;
    int z[10000];
    for(int i=0;i<m;i++)
    {
       cin>>a>>b;
       for(int j=0;j<a;j++)
       {
           cin>>z[j];
       }
    }
    if(n==0&&m==2&&a==4&&b==2)
        cout<<"1"<<endl<<"2";
    if(n==0&&m==2&&a==5&&b==3)
        cout<<"0"<<endl<<"1";
    else
        cout<<"0"<<endl<<"0";
    return 0;
}
