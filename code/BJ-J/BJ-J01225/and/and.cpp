#include<bits/stdc++.h>
using namespace std;
int a[200050];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx)mx=a[i];
    }
    if(m==1)cout<<mx;
    return 0;
}
