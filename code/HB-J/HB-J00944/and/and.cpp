#include<bits/stdc++.h>
using namespace std;
long long a[10010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b;
        a[i]=b;
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i+1])
            swap(a[i],a[i+1]);
    }
    int mini;
    for(int i=1;i<=m;i++)
    {
        mini=min(a[i],a[i+1]);
    }
    cout<<mini;
    return 0;
}
