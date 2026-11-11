#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    else if(m==n){
        maxx=a[1];
        for(int i=2;i<=n;i++){
            maxx=maxx&a[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            maxx=max(maxx,a[i]&a[j]);
        }
    }
    cout<<maxx;
    return 0;
}
