#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,ans=1e9;
int w[500007],d,q;
struct sw{
    int k;
    int a[500007];
    int t[500007];
}S[507];
void dfs(int x,int y,int time){
    for(int i=1;i<=S[x].k;i++){
        if(S[x].a[i]==y){
            ans = min(ans,time);
            return;
        }
    }
    dfs(S[x].a[i],y,time+S[x].t[i]);
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> S[i].k;
        for(int j=1;j<=S[i].k;j++)
            cin >> S[i].a[j] >> S[i].t[j];
    }
    int X,Y;
    while(q--){
        cin >> X >> Y;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=S[i].k;j++)
                if(S[i].a[j]==X)
                    dfs(i,Y,0);
        cout << w[X]+ans+w[Y] << endl;
    }
    return 0;
}
