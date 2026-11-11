#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,l[500004],s[500005],mi;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(i-1)*l[i];
    }
    for(int i=n;i>=1;i--){
        if(s[i]<=m){
            mi=i;
            break;
        }
    }
    cout<<mi;
    return 0;
}
