#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c,z;
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>n;
    c=0,z=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    c=n/2;
    for(int i=1;i<=c;i++)
    {
        if(b[i]!=b[n-i+1])
        {
            z+=max(a[i],a[n-i+1]);
            if(a[i]<a[n-i+1]) a[i+1]-=a[n-i+1]-a[i];
            if(a[i]>a[n-i+1]) a[n-i]-=a[i]-a[n-i+1];
        }
    }
    cout<<z;
    return 0;
}
