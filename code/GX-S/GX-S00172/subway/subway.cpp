#include<bits/stdc++.h>
using namespace std;
struct subdt{
    int jg,ai,ti;
}xl[505]={};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int mw[505],bg,ed;
    for(int i=1;i<=m;i++){
        cin>>mw[i];
    }
    int x1=0;
    for(int i=1;i<=n;i++){
        cin>>xl[i+x1].jg;
        for(int j=i+1+x1;j<=xl[i].jg+x1;j++){
            cin>>xl[j].ai>>xl[j].ti;
        }
        x1+=xl[i].jg;
    }
    cout<<xl[1].jg;
    while(q--){
        cin>>bg>>ed;
        int ans=0;
        ans+=mw[bg]+mw[ed];
        cout<<ans;
    }

return 0;
}

