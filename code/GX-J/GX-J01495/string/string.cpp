#include<bits/stdc++.h>
using namespace std;
#define N [100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0;
    cin>>n;
    string z;
    long long a[n],c=-1;
    char b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        c=c+a[i];
        for(int j=0;j<a[i];j++)
        {
            z=z+b[i];
        }
    }
    //cout<<c<<endl;
    if(c%2==0)
    {
    for(int i=0;i<c/2;i++)
    {
        //cout<<s<<" ";
        if(z[i]!=z[c-i])
        {
            s=s+1;
        }
    }
    }
    else{
        for(int i=0;i<(c-1)/2;i++)
        {
            //cout<<z[i]<<" "<<z[c-i]<<" ";
            if(z[i]!=z[c-i])
            {
                s=s+1;
            }
        }
    }
    cout<<s;
    return 0;
}
