#include<bits/stdc++.h>
using namespace std;
struct num{
    int val,tv;
};
bool cmp(const num& a,const num& b){
    if(a.val!=b.val)return a.val>b.val;
    return a.tv>b.tv;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans;
    cin>>n>>m;
    num a[n+3];
    for(int i=1;i<=n;i++){
        cin>>a[i].tv;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;;j*=2){
            if(j>a[i].tv){
                a[i].val=a[i].tv-j/2;
                break;
            }
        }
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1].tv;
    for(int i=2;i<=m;i++)ans&=a[i].tv;
    cout<<ans;
    return 0;
}