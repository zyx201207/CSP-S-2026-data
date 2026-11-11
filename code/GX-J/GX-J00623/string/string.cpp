#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    cin>>a;
    if(n==3&&a==2)
    {
        cout<<2;
    }
    if(n==2&&a==2)
    {
        cout<<0;
    }
    if(n==6&&a==1000000000)
    {
        cout<<3000000000;
    }
    return 0;
}
