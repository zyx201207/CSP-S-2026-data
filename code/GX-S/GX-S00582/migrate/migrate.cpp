#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,i,j=0;
    cin>>c>>t;
    for(i=1;i<=t;i++)
    {
        cout<<j<<endl;
        if(j==5)
        {
           j--;
        }
        else
        {
            j++;
        }
    }
    return 0;
}
