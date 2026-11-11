#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n,m;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        if(s<=a[i]&a[i+1])s=a[i]&a[i+1];
    }
    cout<<s;
    return 0;
}
