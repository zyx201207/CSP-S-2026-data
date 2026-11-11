#include<bits/stdc++.h>
#define int long long
#define cialo return
using namespace std;
const int N=5e5+10;
int n,m,cnt;
struct _{
    int a;
    bool ff=1;
}q[N];
void dfs(int b,int s,int ans,int no){
    for(int i=1;i<=n;i++){
        if(i==no)continue;
        int x=q[i].a;
        if(x>b)continue;
        if(b-x<=s&&q[i].ff){
            q[i].ff=0;
            dfs(b,s-(b-x),ans+1,no);
            q[i].ff=1;
        }
    }
    cnt=max(cnt,ans);
    cialo ;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>q[i].a;
    }
    if(n>200){
        int num=1;
        for(int i=1;i<=n;i++){
            m-=i;
            if(m>=0)num++;
            else break;
        }
        cout<<num;cialo 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)q[j].ff=1;
        dfs(q[i].a,m,1,i);
    }
    cout<<cnt;
    cialo 0;
}
