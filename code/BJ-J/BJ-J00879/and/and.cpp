#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[200005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    if(m==n){
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }
    cout<<a[m];
    return 0;
}
