#include <bits/stdc++.h>
using namespace std;
int maxx=-0x3f3f3f3f;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool u=1;
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=i;j<=m;j++){
            if(u){
                ans=a[j];
                u=0;
            }else{
                ans=ans&a[j];
            }
        }
        maxx=max(ans,maxx);
        u=1;
    }



    cout<<maxx;
    return 0;

}
