#include<iostream>
using namespace std;
int main()
{
    int n,x,sum=0,u=0;
    string s,a;
    freopen("string.in","t","stdin");
    freopen("string.out","w","stdout")
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>s;
        u+=x;
        for(int j=1;j<=x;j++)
        {
            a+=s;
        }
    }
    for(int i=0;i<u/2;i++)
    {
        if(a[i]!=a[u-i-1])
        {
            sum++;
            continue;
        }
    }
    cout<<sum;
    return 0;
}

