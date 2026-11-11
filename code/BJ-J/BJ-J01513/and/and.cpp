#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
struct node{
    int num,one,w;
};
node a[N];
long long ans;
bool cmp(node x,node y){
    if(x.w!=y.w) return x.w>y.w;
    return x.one>y.one;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        int t=a[i].num;
        while(t){
            if(t%2==1){
                a[i].one++;
            }
            t/=2;
            a[i].w++;
        }
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1].num;
    for(int i=2;i<=m;i++)
        ans=ans&a[i].num;
    cout<<ans;
    return 0;
}
