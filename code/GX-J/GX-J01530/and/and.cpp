#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+1+n);
        ans=a[n];
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                else ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else{sort(a+1,a+1+n);
        ans=a[n-m+1];
    }
    cout<<ans;
    return 0;
}
