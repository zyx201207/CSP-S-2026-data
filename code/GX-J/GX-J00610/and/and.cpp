#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=a[0];
    if (m==n){
        for (int i=1;i<n;i++){
            x&=a[i];
        }
    }
    else {
        sort(a,a+n);
        for (int i=1;i<m;i++)
            x&=a[i];
    }
    cout<<x;
    return 0;
}
