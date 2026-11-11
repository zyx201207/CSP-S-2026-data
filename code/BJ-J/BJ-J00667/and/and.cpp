#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans = a[1];
    cout<<a[1]<<" "<<ans<<endl;
    for(int i=2;i<=m;++i){
        ans &= a[i];
        cout<<a[i]<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
