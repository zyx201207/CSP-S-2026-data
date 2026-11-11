#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,f,ans,minx=2147483647,cnt,a[2000005];
void dfs(int x,int idx,int y){
    if(minx==1) return ;
    if(f>minx) return;
    if(x==y){
        if(f<minx){
            minx=f;
            cnt=1;
        }
        else if(f==minx) cnt++;
        //cout<<' '<<f<<' '<<cnt<<'\n';
        return ;
    }
    for(int i=idx+1;i<=n;i++){
        //cout<<' '<<a[i]<<a[i]-x<<d;
        if(a[i]-x<=d){
            f++;
            dfs(a[i],i,y);
            f--;
        }
        else break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                //cout<<a[i]<<' '<<a[j]<<'\n';
                minx=2147483647,cnt=0,f=0;
                dfs(a[i],i,a[j]);
                if(cnt==2){
                    //cout<<'y';
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }


    return 0;
}
