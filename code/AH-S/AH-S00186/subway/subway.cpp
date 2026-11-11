#include<bits/stdc++.h>
using namespace std;
int C,n,m,d,q,k,x,y,min_a=2147483647;
bool map_[20005][505],isarr,isopen=1;
int ltime[20005][505];
int station[20005];
void digui(int a,int e,int ans,int tr){
    //cout<<ans<<endl;
    if(map_[a][tr]==0){
        //cout<<"line 9-12 do"<<endl;
        digui(a,e,ans,tr+1);
    }
    if(isopen){
        ans+=ltime[a][tr];
        isopen=0;
    }
    if(map_[e][tr]){
        //cout<<"line 13-17 do"<<ans<<endl;
        min_a=min(min_a,ans+ltime[e][tr]);
        isarr=1;
        return;
    }
    for(int i=a+1;i<=m;i++){
        //cout<<"line 18-23 do"<<ans<<endl;
        if(map_[i][tr]==1&&map_[i][tr+1]==1){
            //printf("%d  %d\n",ltime[i][tr],ltime[i][tr+1]);
            digui(i,e,ans+ltime[i][tr]+ltime[i][tr+1],tr+1);
            if(isarr) return;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>station[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int l,ll;
            cin>>l>>ll;
            map_[l][i]=1;
            ltime[l][i]=ll;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        int cost=station[x]+station[y];
        digui(x,y,0,1);
        //cout<<cost<<" "<<min_a<<endl;
        cout<<cost+min_a<<endl;
        min_a=2147483647;
        isarr=0;
        isopen=1;
    }
    return 0;
}
