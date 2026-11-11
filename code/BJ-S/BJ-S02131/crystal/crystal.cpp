#include <bits/stdc++.h>
using namespace std;

long long n,m;
int crys[500010];
long long ops[500010];

int main()
{
    freopen("crystal.in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>crys[i];
    }
    sort(crys,crys+n);
    int maxsum=1;
    ops[0]=0;
    int spos=-1;
    for(int i=1;i<n;i++)
    {
        ops[i]=ops[i-1]+(i-spos-1)*(crys[i]-crys[i-1]);
        if(ops[i]<=m)
        {
            maxsum=max(maxsum,i-spos);
        }else
        {
            while(ops[i]>m&&spos<=i){
                spos++;
                ops[i]=ops[i]-(crys[i]-crys[spos]);
            }
            maxsum=max(maxsum,i-spos);
        }
    }
    freopen("crystal.out","w",stdout);
    cout<<maxsum;
    return 0;
}
