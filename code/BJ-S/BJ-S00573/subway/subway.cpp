#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,f[100009],s[2009][2009],z[100009],ans;
vector<long long>a[100009];
void asd(long long now,long long pay,long long to){
    if(now==to){
        cout<<"pay:"<<pay<<endl;
        ans=min(ans,pay);
        return ;
    }
    for(int i=0;i<a[now].size();i++){
        if(z[a[now][i]]!=1){
            z[a[now][i]]=1;
            cout<<now<<"->"<<a[now][i]<<" cost:"<<s[now][a[now][i]]<<endl;
            asd(a[now][i],pay+s[now][a[now][i]],to);
            z[a[now][i]]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>f[i];
    }
    for(int i=m+1;i<=n+m;i++){
        long long k,v,r;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>v>>r;
            a[i].push_back(v);
            a[v].push_back(i);
            s[i][v]=r;
            s[v][i]=r;
        }
    }
    for(int i=1;i<=q;i++){
        ans=1000000009;
        long long x,y;
        cin>>x>>y;
        cout<<x<<'-'<<y<<endl;
        asd(x,0,y);
        cout<<ans+f[x]+f[y]<<endl;
        for(int i=1;i<=n+m;i++) z[i]=0;
    }
    return 0;
}
