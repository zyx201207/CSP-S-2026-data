#include<bits/stdc++.h>
using namespace std;
int a[500005];
char b[32];
char sum[32]={1};
int n,m,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n];
    return 0;
}