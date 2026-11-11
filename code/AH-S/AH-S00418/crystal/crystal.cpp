#include<bits/stdc++.h>
using namespace std;
int n;
long long s=-2147483647;
long long a[500100]={0},h[500100]={0};
unsigned long long m;
int main(void)
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        h[i]=h[i-1]+(a[i]-a[i-1])*(i-1);
    }
    for(int i=1;i<n;i++)
    {
        if(s==-2147483647)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(h[j]-h[i]<=m && s<(j-i+1))
                {
                    //cout<<h[j]-h[i]<<endl;
                    s=j-i+1;
                }
            }
            continue;
        }
        if(n-i<s)break;
        for(int j=i+s;j<=n;j++)
        {
            if(h[j]-h[i]<=m && s<(j-i+1))
            {
                //cout<<h[j]-h[i]<<endl;
                s=j-i+1;
            }
        }

    }
    cout<<s;
    return 0;
}
