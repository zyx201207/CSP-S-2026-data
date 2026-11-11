#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,n,m,d,q,w[600000],k[1000],a[1000][1000],t[1000][1000],w2[1000005];
ll h[1000005],to[1000005],s[1000005],cnt,nxt[1000005],ans[1000005],tag[1000005];
vector<int> c[600000];
void adde(int st,int en,int x){
    cnt++;
    to[cnt]=en;
    s[cnt]=x;
    nxt[cnt]=h[st];
    h[st]=cnt;
}
void f(int x){
    while(1){
        int start=0;
        for(int i=1;i<=m*n;i++){
            if(ans[i]<ans[start]&&!tag[i]&&h[i])start=i;
        }
        if(start==0)return;
        tag[start]=1;
        for(int i=h[start];i>0;i=nxt[h[i]]){
            if(tag[to[i]]==1)continue;
            if(s[i]+ans[start]<ans[to[i]])ans[to[i]]=s[i]+ans[start];
        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>p>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    ll x,y,cnt0,xe;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            xe=a[i][j];
            x=m*(i-1)+a[i][j];
            cin>>t[xe][i];
            c[xe].push_back(i);
            if(c[xe].size()>1){
                for(int v=0;v<c[xe].size()-1;v++){
                    y=m*(c[xe][v]-1)+a[c[xe][v]][1];
                    adde(x,y,t[xe][i]+t[xe][c[xe][v]]);
                    adde(y,x,t[xe][c[xe][v]]+t[xe][i]);
                }
            }
            if(j>1){
                y=m*(i-1)+a[i][j-1];
                adde(x,y,0);
                adde(y,x,0);
            }

        }
    }
    int xr,yr,j,anss,ans1;
    while(q--){
        cin>>xr>>yr;
        anss=1e9;
        for(int i=0;i<c[xr].size();i++){
            j=c[xr][i];
            for(int v=0;v<=m*n;v++){
                ans[v]=1e9;
                tag[v]=0;
            }
            ans1=w[xr]+t[xr][j];
            ans[(j-1)*m+xr]=0;
            f((j-1)*m+xr);
            for(int v=0;v<c[yr].size();v++){
                j=c[yr][v];
                if(anss>ans1+ans[(j-1)*m+yr]+w[yr]+t[yr][j])anss=ans1+ans[(j-1)*m+yr]+w[yr]+t[yr][j];
            }
        }
        cout<<anss<<endl;

    }

    return 0;
}

