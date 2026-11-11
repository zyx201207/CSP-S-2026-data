#include<bits/stdc++.h>
#define int long long
using namespace std;
struct an{
    int a,s;
};
string x2(int x){
    char t[35];
    int i=1;
    string tans;
    while(x){
        t[i++]=x%2+'0';
        x/2;
    }
    while(i){
        tans+=t[i--];
    }
    return tans;
}
an b[200005];
int n,m,ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
   
    for(int i=1;i<=n;i++){
        cin>>b[i].a;
        ans=max(ans,b[i].a);
    }
    cout<<ans;
    return 0;
    
//    else{
//        for(int i=1;i<=n;i++){
//            cin>>b[i].a;
//            b[i].s=x2(b[i].a);
//        }
//    }
//    cout<<1&2;
    return 0;
}
