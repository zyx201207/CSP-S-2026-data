
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
//    ios::sync_whitout_stdio(false);
   // cin.tie(0);
    int m,n,a;
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=m;i++){
        cin>>a;
        if(a>maxn){
            maxn=a;
        }
    }
    cout<<maxn;
    return 0;
}
