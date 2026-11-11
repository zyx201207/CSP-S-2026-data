#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma=-0x3f3f3f3f;
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ma=max(ma,a[i]);
        }
        cout<<ma;
    }


    return 0;
}
