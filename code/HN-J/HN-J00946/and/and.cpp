#include <bits/stdc++.h>

using namespace std;

long long n,m,a[210000],k,s=0;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //int k=31&15&7;
    //cout<<k;
    stable_sort(a+1,a+1+n);
	/*
    for(int i=n;i>=1;i--)
    {
        cout<<a[i];
    }*/
    for(int i=n;i>=n-m+1;i--)
    {
        //cout<<a[i]<<'=';
        k=a[i];
        for(int j=1;j<m;j++)
        {
            k=k&a[i-j];
            //cout<<k<<endl;
        }
        if(k>s)
        {
            s=k;
        }

    }
    cout<<s;
    return 0;
}
