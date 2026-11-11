#include<bits/stdc++.h>
using namespace std;
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
int b[10000000];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b[i]=x;
    }
    sort(b+1,b+n+1);
    cout<<b[n-m+1];
    return 0;
}



