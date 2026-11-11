#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("text.in","r",stdin);
    freopen("text.out","r",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n];
    int b;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            b=a[i];
            a[i]=a[i+1];
            a[i+1]=b;        
        }
        if(i==n-1)
        {
            break;
        }
    }
    b=a[i]+a[i+1];
    int s=0;
    for(int i=3;i<n;i++)
    {
        if(a[i]=a[2])
        {
            s++;
        }
    }
    cout<<s+3;
    fclose(stdin);
    fclose(stdout);
}
