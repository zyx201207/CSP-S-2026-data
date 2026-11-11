#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int ans=0;
struct num{
    int zhi,shu;
}a[N];
int lowbit(int x){
    return x&(x-1);
}
bool cmp(num b,num c){
    return b.shu>=c.shu;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].zhi;
        a[i].shu=0;
        int lin=a[i].zhi;
        while(lin>0){
            lin=lowbit(lin);
            a[i].shu++;
        }
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++){
    //    cout<<a[i].zhi<<' ';
    //}
    ans=INT_MAX;
    for(int i=1;i<=m;i++){
        ans&=a[i].zhi;
    }
    cout<<ans;
    return 0;
}
