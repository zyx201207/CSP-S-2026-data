#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,sum;
    string a,b;
    cin>>n>>a>>m>>b;
    if(n==m)
    {
        sum+=1000;
    }
    cout<<sum;
    return 0;
}
