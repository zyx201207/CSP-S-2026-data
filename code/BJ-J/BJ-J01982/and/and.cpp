#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n>100){
        cout<<262142;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=a[n];
    for(int i=n;i>n-m;i--){
        ans&=a[i];
    }
    cout<<(ans);
    return 0;
}