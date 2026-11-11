#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[100010],max1;
int and1(int a1,int b,int c)
{
    if(b==0) return a1;
    a1=a1&a[c];
    b--;c++;
    return and1(a1,b,c);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(max1<and1(a[i],m-1,j))
                max1=and1(a[i],m-1,j);
    cout<<max1;
    return 0;
}
