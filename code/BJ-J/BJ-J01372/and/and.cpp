#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int x,int y){
return x>y;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n; int b;
    cin>>n>>b;
    int a[200001]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int b1[200001];
    for(int i=1;i<=b;i++){
        b1[i]=a[i];
    }
    int ans=a[1];
    for(int i=1;i<=b;i++){
        ans&=b1[i];
    }
    cout<<ans;
    return 0;
}

