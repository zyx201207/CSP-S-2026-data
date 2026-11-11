#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,maxn2;
int a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    if(m==2){
        for(int i=n;i>=1;i--){
            for(int j=i-1;j>=1;j--){
                maxn=max(maxn,a[i]&a[j]);
                //cout<<maxn<<" "<<a[i]<<" "<<a[j]<<endl;
            }
        }cout<<maxn<<endl;
    }else if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }cout<<maxn;
    }else if(m==n){
        for(int i=1;i<=n;i++){
            maxn=maxn&a[i];
        }cout<<maxn<<endl;
    }
    return 0;
}
