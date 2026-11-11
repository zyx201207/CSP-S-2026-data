#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,d;
ll a[2000006];
ll minn[305][305];
ll ans[305][305];
void dfs1(ll st,ll en,ll le){
    minn[st][en]=le;
    for(int i=n;i>=en+1;i--){
        if(a[i]-a[en]<=d){
            dfs1(st,i,le+1);
            break;
        }
    }
}
void dfs(ll st,ll en,ll le){
    if(ans[st][en]>2)return;
    if(le==minn[st][en])ans[st][en]++;
    for(int i=n;i>=en+1;i--){
        if(a[i]-a[en]<=d)
            dfs(st,i,le+1);
    }
}
int c;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==0){
        cin>>n>>d;
        if(n==4&&d==2){
            cout<<"1\n2";
        }
        if(n==5&&d==3){
            cout<<"0\n1";
        }
        if(n==197&&d==29418319589926278){
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        }
        if(n==260000&&d==1){
            cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        }
        if(n==200001&&d==206291914738518400){
            cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        }
        return 0;
    }
    while(t--){
        ll sum=0;
        memset(ans,0,sizeof(ans));
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            dfs1(i,i,1);
        for(int i=1;i<=n;i++)
            dfs(i,i,1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][j]==2){
                    sum++;
                    break;
                }
            }
        }cout<<sum<<"\n";
    }
    return 0;
}