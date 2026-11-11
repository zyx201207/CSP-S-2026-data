#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    unsigned long long n,m,sum=0,x=INT_MAX;
    unsigned long long a[200005];
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    if(m==2){
        sort(a+1,a+1+n);
        cout<<(a[n]&a[n-1]);
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=n-m+1;i--){
        x=x&a[i];
    }
    cout<<x;
    return 0;
}
