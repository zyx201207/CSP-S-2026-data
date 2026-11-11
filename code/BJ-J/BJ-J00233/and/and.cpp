#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
struct Node{
    int num,c1,bl;
}a[N];
int fun(int n){
    int ret=0;
    while(n){
        ret+=n&1;
        n>>=1;
    }
    return ret;
}
int fun2(int n){
    int ret=0;
    while(n){
        ret++;
        n>>=1;
    }
    return ret;
}
bool cmp(Node x,Node y){
    return x.num>y.num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].c1=fun(a[i].num);
        a[i].bl=fun2(a[i].num);
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1].num;
        return 0;
    }
    int ans=a[1].num;
    for(int i=2;i<=m;i++){
        ans&=a[i].num;
    }
    cout<<ans;
    return 0;
}
