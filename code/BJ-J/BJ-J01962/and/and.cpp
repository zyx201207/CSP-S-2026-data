#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t,s=0;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-m;i++){
        t=a[i];
        for(int j=i;j<i+m;j++)
            t=t|a[i];
        if(t>s)
            s=t;
    }
    cout<<s;
    return 0;
}
