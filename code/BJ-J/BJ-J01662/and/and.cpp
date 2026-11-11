#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){//(m=1)checkpoint6
        for(int i=1;i<=n;i++){
            cin>>m;
            ans=max(m,ans);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
