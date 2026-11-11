#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{typedef long long ll;
    constexpr int maxn=2e6+3;ll coo[maxn];
    int nex[2][maxn],f[2][maxn];vector<int>tree[2][maxn];
    inline int Main(){int testcase,test;cin>>testcase>>test;while(test--){
        int n;ll lim;cin>>n>>lim;for(int i=1;i<=n;++i)cin>>coo[i];
        /*static int count=0;if(++count!=6)continue;
        clog<<n<<' '<<lim<<'\n';for(int i=1;i<=n;++i)clog<<coo[i]<<' ';clog<<'\n';*/
        for(int i=1,last=1;i<=n;++i){while(last<i&&coo[i]-coo[last]>lim)++last;
            nex[0][i]=last!=i?last:0;if(last!=i)tree[0][last].push_back(i);}
        for(int i=n,last=n;i;--i){while(last>i&&coo[last]-coo[i]>lim)--last;
            nex[1][i]=last!=i?last:0;if(last!=i)tree[1][last].push_back(i);}
        for(int i=1;i<=n;++i)for(int siz=tree[1][i].size(),j=0;j<siz>>1;++j)
            swap(tree[1][i][j],tree[1][i][siz-j-1]);
        /*clog<<"nex:\n";for(char i=0;i<2;clog<<'\n',++i)
            for(int j=1;j<=n;++j)clog<<nex[i][j]<<' ';*/
        for(int i=n;i;--i){if(!nex[1][i]){f[0][i]=0;continue;}
            vector<int>::iterator ite=upper_bound(tree[0][i].begin(),tree[0][i].end(),nex[1][i]);
            if((f[0][i]=ite-tree[0][i].begin())&&ite[-1]==nex[1][i])f[0][i]+=f[0][nex[1][i]];}
        for(int i=1;i<=n;++i){if(!nex[0][i]){f[1][i]=0;continue;}
            vector<int>::iterator ite=lower_bound(tree[1][i].begin(),tree[1][i].end(),nex[0][i]);
            if((f[1][i]=tree[1][i].end()-ite)&&*ite==nex[0][i])f[1][i]+=f[1][nex[0][i]];}
        ll ans=0;for(int i=2;i+1<n;++i)if(nex[0][i]&&nex[1][i+1]){
            vector<int>::iterator ite=upper_bound(tree[0][i].begin(),tree[0][i].end(),nex[1][i+1]);
            int rig=ite-tree[0][i].begin();if(rig&&ite[-1]==nex[1][i+1])rig+=f[0][nex[1][i+1]];
            if(rig&&tree[0][i].front()==i+1)--rig;
            ite=lower_bound(tree[1][i+1].begin(),tree[1][i+1].end(),nex[0][i]);
            int lef=tree[1][i+1].end()-ite;if(lef&&*ite==nex[0][i])lef+=f[1][nex[0][i]];
            if(lef&&tree[1][i+1].back()==i)--lef;
            ans+=(ll)lef*rig;//if(lef&&rig)clog<<"position:"<<i<<' '<<rig<<' '<<lef<<'\n';
        }for(int i=1;i<=n;++i)tree[0][i].clear(),tree[1][i].clear();
        cout<<ans<<'\n';
        }return 0;
    }
}
int main(){freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    SOLUTION::Main();return 0;
}