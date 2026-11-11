#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
const int maxn=2000005;
int cid,T,n,g1[maxn],g2[maxn],g1_[maxn],g2_[maxn],tol[maxn],tor[maxn];
ll d,p[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>cid>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>p[i],g1[i]=g2[i]=g1_[i]=g2_[i]=0;
        for(int i=1,j=1;i<=n;++i){
            while(j<n&&p[j+1]-p[i]<=d)++j;
            tor[i]=j;
            //printf("%d %d\n",i,j);
        }
        for(int i=n,j=n;i>=1;--i){
            while(j>1&&p[i]-p[j-1]<=d)--j;
            tol[i]=j;
            //printf("%d %d\n",i,j);
        }
        for(int i=1;i<=n;++i)if(tor[i]>i){
            g1[tor[i]]++;
            if(tor[i]>i+1)g1_[tor[i]]++;
            if(tol[tor[i]]==i)g1[tor[i]]+=g1[i];
            if(tor[i]>i+1&&tol[tor[i]-1]==i)g1_[tor[i]]+=g1[i];
        }
        for(int i=n;i>=1;--i)if(tol[i]<i){
            g2[tol[i]]++;
            if(tol[i]<i-1)g2_[tol[i]]++;
            if(tor[tol[i]]==i)g2[tol[i]]+=g2[i];
            if(tol[i]<i-1&&tor[tol[i]+1]==i)g2_[tol[i]]+=g2[i];
        }
        ll ans=0;
        for(int i=2;i<=n;++i)ans+=(ll)g1_[i]*g2_[i-1]/*,printf("%d %d %d\n",i,g1_[i],g2_[i])*/;
        cout<<ans<<'\n';
    }
    return 0;
}