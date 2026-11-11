#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+2;
int n,m,a[maxn],ans=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n-m+1;i++){
        int mx=a[1];
        if(m==1){ans=a[i];break;}
        else{
            for(int j=0;j<m-1;j++){
                mx=(mx&a[i+j]);
            }
        }
        ans=max(ans,mx);
    }
    cout<<ans<<'\n';
    return 0;
}
