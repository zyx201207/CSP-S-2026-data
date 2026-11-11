#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    long long pos=1;
    while(m>0)
    {
        if(a[pos]==a[pos+1])pos++;
        else
        {
            a[pos]++;
            m-=pos;
        }
    }
    while(a[pos]==a[pos+1])pos++;
    cout<<pos;
    return 0;
}
