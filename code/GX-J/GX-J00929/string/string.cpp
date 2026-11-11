#include<bits/stdc++.h>
using namespace std;
long long a[100000001];
char c[10005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string x,y,z,w,e;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            x=x+c[i];
        }
    }
        int ans1=0,ans2=0;
            for(int i=0;i<n/2;i++)
            {
                y[i]=x[i];
            }
            for(int j=n/2+1;j<x.size();j++)
            {
                z[j]=x[j];
            }
            w=y;
            e=z;
            for(int i=0;i<x.size()/2;i++)
            {
                if(w[i]!=e[i])
                {
                    w[i]=e[i];
                    ans1++;
                }
            }
            for(int i=0;i<x.size()/2;i++)
            {
                if(z[i]!=y[i])
                {
                    z[i]=y[i];
                    ans2++;
                }
            }
            if(ans1>ans2)cout<<ans1;
            else if(ans1<ans2)cout<<ans2;
            else if(ans1==ans2)cout<<ans1;
    return 0;
}
