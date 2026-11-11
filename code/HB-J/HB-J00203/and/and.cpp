#include<bits/stdc++.h>
using namespace std;
int n,m,max1,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i+m-1]==a[i]){
            max1=a[i];
        }
    }
    cout<<max1;
    return 0;
}
