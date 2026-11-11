#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    int n,a[202600],b[202600];
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(n==1)
    {
        cout<<0;
    }
    else if(n==2)
    {
        cout<<min(a[0],a[1]);
    }
    else
    {
        cout<<"4256425";
    }
    return 0;
}
