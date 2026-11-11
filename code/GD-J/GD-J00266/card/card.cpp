#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
stack<pair<int,int>>stk;
int a[N],lst[N],nxt[N],mx[N],ans[N],ans1[N];
bool ok[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lst[i]=mx[a[i]];
        nxt[mx[a[i]]]=i;
        mx[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        while(!stk.empty()&&stk.top().second<=i) stk.pop();
        if(stk.empty()) ans[i]=i;
        else ans[i]=i-stk.top().first+ans[lst[a[i]]];
        while(!stk.empty()&&stk.top().second<nxt[i]) stk.pop();
        stk.push({i,nxt[i]});
    }
    for(int i=1;i<=n;i++){
        ans1[a[i]]=max(ans1[a[i]],ans[i]);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[mx[i]]<<" ";
    }
    return 0;
}