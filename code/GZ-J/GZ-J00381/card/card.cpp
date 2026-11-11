//GZ-J00381 º«ÓúĞÅ
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int num[500005];
stack<int> a;
int vis[300005];
int ans[300005];
bool flag=1;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {cin>>num[i];if(num[i]<num[i-1])flag=0;}
    if(flag){
        for(int i=1;i<=n;i++){
            vis[num[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<vis[i]<<' ';
        }
        return 0;
    }
    for(int t=1;t<=n;t++){
        for(int i=t;i<=n;i++){
            int x;
            x=num[i];
            if(vis[x]==t){
                while(!a.empty()&&a.top()!=x) {vis[a.top()]=0;a.pop();}
            }else{
                vis[x]=t;
                a.push(x);
            }
        }
        while(!a.empty()){
            ans[a.top()]++;
            a.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
