#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long m,n,ma=-1e9;
    cin>>m>>n;
    long long a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];+
    }
    for(int i=n;i<m;i++)
    {
        ma=max(ma,a[i] & a[i-1]);
    }
    cout<<ma;
    return 0;
}
