#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a,s[2026],c=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        s[i]=a;
    }
    for(int i=0;i<n-1;i++){
        c=max(s[i],s[i+1]);
        s[i+1]=c;
    }
    cout<<c;
    return 0;
}