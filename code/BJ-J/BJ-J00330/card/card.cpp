#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],pos[maxn],tot,cnt[maxn],last[maxn];
bool ok[maxn];
pair<int,int>qu[maxn];
vector<pair<int,int>>e;
inline bool A(){
    for(int i=1;i<=n;i++)if(a[i-1]>a[i])return 0;
    return 1;
}
inline bool B(){
    int sum=0;
    for(int i=1;i<=n;i++)if(a[i]!=a[i-1])sum++;
    if(sum<=20000)return 1;
    return 0;
}
inline void solveA(){
    for(int i=1;i<=n;i++){
        cnt[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
}
inline void solveB(){
    e.push_back({-1,-1});
    int last=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]!=a[i-1]){
            e[e.size()-1].second=i-last;
            e.push_back({a[i],0});
            last=i;
        }
    }
    int nn=e.size()-2;
    for(int k=1;k<=nn;k++){
        memset(pos,0,sizeof(pos));
        for(int i=k;i<=nn;i++){
            if(pos[e[i].first]!=0){
                for(int j=i-1;j>pos[e[i].first];j--){
                    pos[e[j].first]=0;
                }
            }
            pos[e[i].first]=i;
        }
        for(int i=1;i<=m;i++)if(pos[i]!=0)cnt[i]+=e[k].second;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
}
inline bool m2(){
    return m<=2;
}
inline void solvem2(){
    cnt[a[n]]=n;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[n])cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //if(pos[a[i]])qu[++tot]={pos[a[i]],i};
      //  pos[a[i]]=i;
    }
    if(A()){solveA();return 0;}
    if(B()){solveB();return 0;}
    if(m2()){solvem2();return 0;}
    for(int k=1;k<=n;k++){//cout<<endl<<endl<<endl<<k<<" *** \n";
        memset(pos,0,sizeof(pos));
        for(int i=k;i<=n;i++){//cout<<i<<": "<<endl;
       // cout<<"pos:  ";
       // for(int j=1;j<=m;j++)cout<<pos[j]<<" ";
        //cout<<endl;
            if(pos[a[i]]!=0){
                for(int j=i-1;j>pos[a[i]];j--){
                    pos[a[j]]=0;//cout<<j<<" ";
                }
            }//cout<<endl;
            pos[a[i]]=i;
        }
        for(int i=1;i<=m;i++)if(pos[i]!=0)cnt[i]++;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
