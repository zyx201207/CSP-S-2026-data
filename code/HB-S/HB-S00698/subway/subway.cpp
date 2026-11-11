#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int Ba[520]={0}, c, n, m, d, q, w[114514], k[114514], a[411][514], t[411][514];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][k[i]]>>t[i][k[i]];
    }
    for(int OvO=1;OvO<=q;OvO++){
        int x, y, Lu_x, Lu_y;
        cin>>x>>y;
        cnt=w[x]+w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x==a[i][k[i]]) Lu_x=i;
                if(y==a[i][k[i]]) Lu_y=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(Lu_x==Lu_y){
                if(a[i][k[i]]!=Lu_y) cnt+=t[i][k[i]];
                else if(a[i][k[i]]==Lu_y){
                    cnt+= t[i][k[i]];
                    break;
                }
            }
            else {
                if(a[i][k[i]]==a[i+1][k[i]]){
                    cnt+= t[i+1][k[i]];
                    if(a[i+1][k[i]] == y) {
                        cnt+=t[i+1][k[i]];
                        break;
                    }
                }
                cnt+= t[i][k[i]];

            }
        }
        cout<<cnt-1<<'\n';
    }
    return 0;
}//AC 0
//WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA
