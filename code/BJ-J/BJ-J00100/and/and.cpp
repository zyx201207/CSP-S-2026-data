#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
    int a;
    string s="";
};
Node arr[200010];
bool cmp(Node x,Node y){
    int cntx=0,cnty=0;
    for(int i=0;i<x.s.size();i++){
        if(x.s[i]=='1'){
            cntx++;
        }
    }
    for(int i=0;i<y.s.size();i++){
        if(y.s[i]=='1'){
            cnty++;
        }
    }
    if(cntx!=cnty){
        return cntx>cnty;
    }
    else{
        return x.a>y.a;
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,u=INT_MAX;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a;
        int x=arr[i].a;
        while(x){
            arr[i].s+=(char)('0'+x%2);
            x/=2;
        }
    }
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=m;i++){
        u=u&arr[i].a;
    }
    cout<<u;
    return 0;
}