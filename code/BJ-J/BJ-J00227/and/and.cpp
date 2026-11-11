#include<bits/stdc++.h>
using namespace std;
int o=0,p=0,c=0; 
int a[200001];
bool b[200001];
int dfs(h,ans){
    if(h==m){
        return ans;
    int ans1=ans&a[p];
    for(int j=0;j<n;j++){
        if(ans&a[j]>ans1&&b[j]==0){
            b[c]=0;
            c=j;
            b[j]=1;
            ans1=ans&a[j];
            o=1;
        }
    }
    if(o==0){
        b[p]=1;
        p++;
    }
    o=0;
    c=0;
    dfs(h+1,ans1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    b[n]=1;
    cout<<dfs(0,a[n]);
    return 0;
}
