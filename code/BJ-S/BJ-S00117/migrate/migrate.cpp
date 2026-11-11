#include <bits/stdc++.h>

using namespace std;

const int N=2e6+5;
int c,t,n,d,llll,ll,cnt,bis[N],jcnt;
bool vis[N],l[N],fl;
vector<int>v;

queue<int>q;

int bfs(int u,int v){
    while(!q.empty()){
        q.pop();
    }
    for(int i=u;i<=v;i++){
        vis[i]=0;
        bis[i]=0;
    }
    q.push(u);
    fl=0;
    jcnt=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=p+1;i<=p+d;i++){
            if(l[i]==0)continue;
            if(i==v){
                if(bis[p]+1==bis[v]){
                    jcnt++;
                }else{
                    bis[i]=bis[p]+1;
                }
            }else{
                q.push(i);
                bis[i]=bis[p]+1;
                vis[i]=1;
            }
        }
    }
    if(jcnt==2){
        return 1;
    }
    return 0;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cnt=0;
        cin>>n>>d;
        v.clear();
        for(int i=0;i<N;i++){
            l[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>llll;
            v.push_back(llll);
            l[llll]=1;
        }
        if(d==1){
            cout<<0<<"\n";
            continue;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(abs(j-i)<=1)continue;
                ll=abs(j-i);
                if(d>=ll)continue;
                cnt+=bfs(i,j);
            }
        }
        cout<<cnt<<"\n";
    }
}
