#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
                 int k=0;
        for(int c=j;c<j+i;c++) k+=a[c];
            if(a[j+i-1]*i-k<=m){
                ans=max(ans,i);
            }
        }
    }
    cout<<ans;
return 0;
}
