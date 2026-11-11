#include<bits/stdc++.h>
using namespace std;
int n,y=0;
long long m,x=1,all;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int a[n+1]={0};
    char c[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        m+=a[i];
        if(c[i]!=c[i-1])y=1;
    }
    if(y==0){
        cout<<0;
        return 0;
    }
    char s[m+1]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s[x]=c[i];
            x++;
        }
    }
    if(m%2==0)
    {
        for(int i=1;i<=m/2;i++)
        {
            if(s[i]!=s[m-i+1])all++;
        }
    }
    else
    {
        for(int i=1;i<=(m-1)/2;i++)
        {
            if(s[i]!=s[m-i+1])all++;
        }
    }
    cout<<all;
    return 0;
}
