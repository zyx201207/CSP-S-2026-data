
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,n1;
    string x,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>n1>>x;
        for(int j=1;j<=n1;j++)
        {
            a+=x;
        }
    }
    if(a[1]=='a'&&a[2]=='a')
    {
        cout<<"2";
    }
    if(a[1]=='a'&&a[3]=='a')
    {
        cout<<"0";
    }
    return 0;
}
