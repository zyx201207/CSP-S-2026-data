#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
return a>b;}
int n,m,b=0,c=0;
int ans[10000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            b=a[i]&a[i+j];
        }
        ans[i]=b;
    }
    sort(ans,ans+n,cmp);
    cout<<ans[0];
    return 0;}
