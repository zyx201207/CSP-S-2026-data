#include<bits/stdc++.h>
using namespace std;
struct XX{
    int v,sum1;
};
XX a[200005];
int n,m;
bool cmp(XX a1,XX b1){
    if(a1.sum1!=b1.sum1){
        return a1.sum1>b1.sum1;
    }
    else{
        return a1.v>b1.v;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].v;
    }
    for(int i=1;i<=n;i++){
        int i1=a[i].v;
        int cnt=0;
        while(i1!=0){
            cnt+=i1%2;
            i1>>=1;
        }
        a[i].sum1=cnt;
    }
    sort(a+1,a+n+1,cmp);
    int ans;
    ans=a[1].v;
    for(int i=2;i<=m;i++){
        ans&=a[i].v;
    }
    cout<<ans;
    return 0;
}
