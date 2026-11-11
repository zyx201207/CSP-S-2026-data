#include<bits/stdc++.h>

using namespace std;
int a[500005] = {0};
int b[500005] = {0};
int c[500005] = {0};
int cnt = 0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            b[j] = a[j];
            for(int h = j-1;h>=i;h--)
            {
                if(b[h] == b[j])
                {
                    for(int bb = h;bb<j;bb++)
                    {
                        b[bb] = 0;
                    }
                    break;
                }
            }
        }
        for(int kk = 1;kk<=m;kk++)
        {
            for(int k = i;k<=n;k++)
            {
                if(b[k] == kk)c[kk]++;
            }
        }
    }
    for(int i = 1;i<=m;i++)cout<<c[i]<<" ";
    return 0;
}

