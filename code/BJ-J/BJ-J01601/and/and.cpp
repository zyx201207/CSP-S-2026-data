#include<bits/stdc++.h>
using namespace std;
int aa=1;
int ans=0;
const int N=2e5;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+2,a+n+2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10000;j++){
            if(a[n-m+1]>aa){
                aa*=2;
            }
            else if(a[n-m+1]==0)break;
            else{
                ans+=aa/2;
                for(int k=0;k<m;k++){
                    a[n-k]-=aa/2;
                }aa=1;
        }}}
    cout<<ans+1;
}
