#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    int m[100005];
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>m[i];
    }
    int ans=0;
    for(int i=1;i<=a;i++){
        if(m[i]<ans){
            ans=m[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
