#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(m==n-1)
        cout<<a[n-1];
    else
        cout<<a[n-m];
    return 0;
}
