#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,x[2000005];
    double d;
    for(int q=1;q<=t;q++)
    {
        cin>>n>>d;
        if(n<4)
        {
            cout<<0;
            return 0;
        }
        if(x[5]-x[4]==x[4]-x[3]&&x[3]-x[2]==x[2]-x[1])
        {
            cout<<ceil(d/4);
        }
        else
        {
            int n;
            cout<<n;
        }
    }
    return 0;
}
