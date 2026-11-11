#include<bits/stdc++.h>
using namespace std;
int n,m,minn,b;
long long int d[100000002];
void dfs(int l,int r,int f){
    if(f>minn) return ;
    if(l==r){
        if(f<minn){
            minn=f;
            b=1;
        }
        else if(f==minn){b++;}
        return ;
    }
    int w=0;
    for(int i=l+1;i<n;i++){
        w+=d[i];
        if(w>m) break;
        dfs(i,r,f+1);
    }
    return ;
}
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        long long int temp = 0;
        for(int j=0;j<n;j++){
            long long int g = 0;
            cin>>g;
            d[j]=g-temp;
            temp=g;
        }

        int ans=0;
        for(int l=0;l<n-3;l++){
            for(int j=l+3;j<n;j++){
                minn=INT_MAX;
                b=0;
                dfs(l,j,0);
                if(b==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
