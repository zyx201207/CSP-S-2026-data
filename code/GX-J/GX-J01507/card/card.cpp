#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,m;
    cin>>m;
    int a[m+1]={0};
    for(int i=1;i<=m;i++)
    {
        sum+=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    cout<<sum;
    return 0;
}
