#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1000005;
void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int c,t,n,k,dep[3][N],f[2][N],mxx[3][N],dp[3][N];
vector<int> g[N];
void kfc1(int i,int fa){
    int mx1=0,mx2=0;
    for(auto j:g[i]){
        if(j==fa) continue;
        // cout<<i<<" "<<fa<<" "<<j<<endl;
        dep[0][j]=dep[0][i]+1;
        kfc1(j,i);
        if(mxx[2][j]>=mx1){
            mx2=mx1,mx1=mxx[2][j];
        }
        else{
            mx2=max(mx2,mxx[2][j]);
        }
        dp[2][i]=max(dp[2][j],dp[2][i]);
    }
    mxx[2][i]=mx1+1;
    dp[2][i]=max({dp[2][i],mx1+mx2+2,mxx[2][i]});
}
void kfc2(int i,int fa){
    f[0][i]=fa;
    int mx1=0,mx2=0;
    for(auto j:g[i]){
        if(fa==j) continue;
        dep[1][j]=dep[1][i]+1;
        kfc2(j,i);
        if(mxx[0][j]>=mx1){
            mx2=mx1,mx1=mxx[0][j];
        }
        else{
            mx2=max(mx2,mxx[0][j]);
        }
        dp[0][i]=max(dp[0][j],dp[0][i]);
    }
    mxx[0][i]=mx1+1;
    dp[0][i]=max({dp[0][i],mx1+mx2+2,mxx[0][i]});
}
void kfc3(int i,int fa){
    f[1][i]=fa;
    int mx1=0,mx2=0;    
    for(auto j:g[i]){
        if(fa==j) continue;
        dep[2][j]=dep[2][i]+1;
        kfc3(j,i);
        if(mxx[1][j]>=mx1){
            mx2=mx1,mx1=mxx[1][j];
        }
        else{
            mx2=max(mx2,mxx[1][j]);
        }
        dp[1][i]=max(dp[1][j],dp[1][i]);
    }
    mxx[1][i]=mx1+1;
    dp[1][i]=max({dp[1][i],mx1+mx2+2,mxx[1][i]});
}
int up[N],down[N],tot,siz[N],dd[N],rt,depp[2][N],mn=1e9;
void getrt0(int i,int fa,int mx){
    int mx1=-1,mx2=-1,idd=0;
    // cout<<i<<"-"<<fa<<" "<<mn<<'\n';
    for(auto j:g[i]){
        if(j==fa) continue;
        if(mxx[0][j]>=mx1){ mx2=mx1,mx1=mxx[0][j],idd=j;}
        else mx2=max(mx2,mxx[0][j]);
    }
    if(max(mx,mx1+1)<mn){
        rt=i;
        // cout<<i<<"+++\n";
        mn=max(mx,mx1+1);
    }
    for(auto j:g[i]){
        if(j==fa) continue;
        if(j==idd)getrt0(j,i,mx2+2);
        else getrt0(j,i,mx1+2);
    }
}
void getrt1(int i,int fa,int mx){
    int mx1=0,mx2=0,idd=0;
    for(auto j:g[i]){
        if(j==fa) continue;
        if(mxx[1][j]>=mx1){ mx2=mx1,mx1=mxx[1][j],idd=j;}
        else mx2=max(mx2,mxx[1][j]);
    }
    if(max(mx,mx1+1)<mn){
        rt=i;
        mn=max(mx,mx1+1);
    }
    for(auto j:g[i]){
        if(j==fa) continue;
        if(j==idd)getrt1(j,i,mx2+2);
        else getrt1(j,i,mx1+2);
    }
}
void getrt2(int i,int fa,int mx){
    int mx1=0,mx2=0,idd=0;
    for(auto j:g[i]){
        if(j==fa) continue;
        if(mxx[2][j]>=mx1){ mx2=mx1,mx1=mxx[2][j],idd=j;}
        else mx2=max(mx2,mxx[2][j]);
    }
    if(max(mx,mx1+1)<mn){
        rt=i;
        mn=max(mx,mx1+1);
    }
    for(auto j:g[i]){
        if(j==fa) continue;
        if(j==idd)getrt2(j,i,mx2+2);
        else getrt2(j,i,mx1+2);
    }
}
vector<int> hv;
int rt1,rt2,rt3,vis1[N],cnt;
void solve(int i,int fa,int jz,int mid){
    hv.push_back(i);
    if(hv.size()>mid+1){
        if(!vis1[hv.size()-mid]){
            cnt++;
            vis1[hv.size()-mid]=1;
        }
    }
    // if(mid==0){
    //     cout<<i<<"-----"<<"\n";
    //     for(auto j:hv){
    //         cout<<j<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(auto j:g[i]){
        if(j==fa||j==jz) continue;
        solve(j,i,jz,mid);
    }
    hv.pop_back();
}
bool check(int mid,int x,int y){
    for(int i=1;i<=n;i++){
        vis1[i]=0;
    }
    cnt=1;
    int mnn=1e9;
    solve(rt3,0,0,mid);
    mnn=min(mnn,cnt);
    // cout<<mnn<<" "<<mid<<" "<<cnt<<'\n';
    cnt=2;
    for(int i=1;i<=n;i++){
        vis1[i]=0;
    }
    solve(rt2,0,y,mid);
    solve(rt1,0,x,mid);
    mnn=min(mnn,cnt);
    return mnn<=k;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(c);read(t);
    while(t--){
        read(n);read(k);
        for(int i=1;i<=n;i++){
            g[i].clear();
            vis1[i]=0,rt1=0,rt2=0,rt3=0,up[i]=0,down[i]=0,tot=0,siz[i]=0,dd[i]=0,rt=0,depp[0][i]=dep[1][i]=0;
            dep[0][i]=dep[1][i]=dep[2][i]=0,f[0][i]=f[1][i]=0,mxx[0][i]=mxx[1][i]=mxx[2][i]=0,dp[0][i]=dp[1][i]=dp[2][i]=0;
        }
        for(int x,y,i=1;i<n;i++){
            read(x);read(y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        kfc1(1,0);
        int id1=1,id2;
        for(int i=2;i<=n;i++){
            if(dep[0][i]>dep[0][id1]){
                id1=i;
            }
        }
        id2=id1;
        kfc2(id1,0);
        for(int i=2;i<=n;i++){
            if(dep[1][i]>dep[1][id2]){
                id2=i;
            }
        }
        kfc3(id2,0);
        int bg=id2;
        while(bg!=id1){
            tot++;
            up[tot]=dp[0][bg];
            bg=f[0][bg];
        }
        bg=id1;
        int yy=tot;
        while(bg!=id1){
            down[yy]=dp[1][bg];
            yy--;
            bg=f[1][bg];
        }
        int mnn=1e9,idd=0;
        for(int i=1;i<=tot;i++){
            if(max(up[i],down[i])<mnn){
                idd=i;
                mnn=max(up[i],down[i]);
                // cout<<up[i]<<" "<<down[i]<<'\n';
            }
        }
        // cout<<id1<<" "<<id2<<'\n';
        int cut=id2;
        idd--;
        while(idd--){
            cut=f[0][cut];
        }
        mn=1e9;
        getrt0(cut,f[0][cut],1);
        // cout<<cut<<"----"<<f[0][cut]<<'\n';
        rt1=rt;
        rt=0;mn=1e9;
        getrt1(f[0][cut],cut,1);
        rt2=rt;
        mn=1e9,rt=0;
        getrt2(1,0,1);
        rt3=rt;
        int l=0,r=1e9,as=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,cut,f[0][cut])){
                as=mid,r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<as<<'\n';
    }
    return 0;
}
//g++ hub.cpp -o hub -std=c++14 -O2 "-Wl,-stack=1234567890" -Wall
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/