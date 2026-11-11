#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,v,cnt,ans;
struct _{
    int a;
    char c;
}q[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q[i].a>>q[i].c;
    }
    v=n/2;
    for(int i=1;i<=v;i++){
        if(i==n-i&&n%2==0){
            cnt+=q[i].a;
        }
        if(q[i].c!=q[n-i].c){
            cnt+=q[i].a;
        }
    }
    for(int i=n;i>=v;i--){
        if(i==n-i&&n%2==0){
            ans+=q[i].a;
        }
        if(q[i].c!=q[n-i].c){
            ans+=q[i].a;
        }
    }
    cout<<min(ans,cnt);
    return 0;
}
