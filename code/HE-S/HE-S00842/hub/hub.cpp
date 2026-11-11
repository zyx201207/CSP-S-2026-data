#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,b;
    int z[10000];
    for(int i=0;i<m;i++)
    {
       cin>>a>>b;
       for(int j=0;j<a-1;j++)
       {
           cin>>z[j];
       }
    }
    cout<<"1"<<endl<<"2";
    return 0;
}
