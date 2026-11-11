#include<bits/stdc++.h>
using namespace std;
long long p[100000000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    unsigned long long n,m,mx=0;
    cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        sort(p,p+n);
        for(int i=1;i<n;i++)
        {
            long long s=m,q,k=1;
            while(s>=0&&i-k-1>=0)
            {
                q=p[i]-p[i-k-1];
                s-=q;
                k++;
                q=0;
            }
            if(k>mx)
                mx=k;
        }
        cout<<mx;
}
