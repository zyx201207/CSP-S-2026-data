#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010],ans=1e18;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=m;i++){
        ans=min(ans,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
