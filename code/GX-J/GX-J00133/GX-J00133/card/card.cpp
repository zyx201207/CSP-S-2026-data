#include<iostream>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a,pai[10000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        pai[i]=a;
    }
    cout<<n<<m<<a;
    return 0;
}
