#include<bits/stdc++.h>
using namespace std;
const long long N=2e4+10;
long long c,n,m,d,q;
long long w[N];//di i hao ti tie kou shi jian
vector<long long> h[N];//yong you zhan kou de di tie xian lu
long long k[550];//di i tiao xian you de di tie kou shu
long long a[550][N];//di i tiao xian di j hao wei zhi dui ying zhan kou
long long t[550][N];//di i tiao xian di j hao wei zhi dui ying zhan kou shi jian
long long mn_=0x3f3f3f3f;//zui duan yong shi
bool flag[550];

void dfs(long long s,long long e,long long now,long long tim,long long xl){//kai shi   jie shu    wei zhi    yong shi    dang qian xian lu
    //if(s==112&&e==57)
    //cout<<s<<" "<<e<<" "<<now<<" "<<tim<<" "<<xl<<"\n";
    if(now==e){
        mn_=min(mn_,tim);
        return;
    }
    if(tim>=mn_)
        return;
    long long las=0;
    //xian zai zai di xl tiao xian lu
    for(int i=1;i<=k[xl];i++)
        if(a[xl][i]==now){
            las=i;
            break;
        }
    for(int i=1;i<=k[xl];i++){
        //if(s==123&&e==131)
        //    cout<<" "<<i<<" "<<a[xl][i]<<"\n";
        //di i hao wei zhi
        if(las!=i){
            if(a[xl][i]==e)
                dfs(s,e,e,tim+t[xl][las]+t[xl][i],xl);
            for(auto j:h[a[xl][i]])
                if(!flag[j]&&j!=xl)
                    dfs(s,e,a[xl][i],tim+t[xl][las]+t[xl][i],j);
        }
    }

    flag[xl]=1;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            h[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        memset(flag,0,sizeof flag);
        long long stri,endi;
        cin>>stri>>endi;
        mn_=0x3f3f3f3f;
        for(auto i:h[stri]){
            dfs(stri,endi,stri,w[stri],i);
        }
        mn_+=w[endi];
        cout<<mn_<<"\n";
    }
}
