#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q;
const long long MAXN=50005;
long long w[MAXN],a[MAXN][MAXN],t[MAXN],l=1,f[MAXN],e[MAXN],minhff;
void dfs(long long dj,long long now,long long js){//dai jia  dang qian weizhi  jieshu di fang
    if(now==js){
        minhff=max(minhff,dj);
    }
    else{
        //while()
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;//du ru ji ben
    for(int i=0;i<m;i++){//du ru suoxu shijian
        cin>>w[i];
    }
    int tmp,tpm;
    for(int i=0;i<n;i++){//ditie luxian
        cin>>tmp;
        for(int i=1;i<m;i++){
            cin>>tpm;
            a[tmp][t[tmp]]=tpm;
            t[tmp]++;
            cin>>tmp;
        }

    }

    for(int i=0;i<q;i++){//du ru jihua bianhao
        minhff=1e9;

        cin>>f[i]>>e[i];
        dfs(0,f[i],e[i]);
        cout<<minhff<<endl;
    }
    return 0;
}
