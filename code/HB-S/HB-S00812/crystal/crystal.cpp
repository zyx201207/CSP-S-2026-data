#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,b=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        a[i]++;
        if(a[i]==a[m/2+1]){
            b++;
        }

    }
    sort(a+1,a+1+n);
    cout<<b+2;
    return 0;
}
