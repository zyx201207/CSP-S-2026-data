#include<bits/stdc++.h>
using namespace std;
int a[200001];
int p[100001];
int b[100001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,t;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        t=0;
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=t;k++)
            {
                if(p[k]==a[j])
                {
                    t=k-1;
                    break;
                }
            }
            p[++t]=a[j];
        }
        for(int j=1;j<=t;j++)
        {
            b[p[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
