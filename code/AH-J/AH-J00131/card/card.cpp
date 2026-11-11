#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
    cout<<'1'<<' ';
    }



    return 0;
}
