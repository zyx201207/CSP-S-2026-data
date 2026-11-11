#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int sum=0,s;
    for(int i=1;i<m;i++){
        s|=a[i]|a[i-1];

    }
    cout<<s;
    return 0;
}
