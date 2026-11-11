#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,minp=1e9;
    int a[500006],ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    int left=0,right=n-1;
    for(int i=1;i<=left;i++){
        for(int j=right;j>=0;j--){
            minp=min(minp,a[j]-a[i]);
            if(i>j){
                
            }
            ans++;
    }
    cout<<ans;
    return 0;
}