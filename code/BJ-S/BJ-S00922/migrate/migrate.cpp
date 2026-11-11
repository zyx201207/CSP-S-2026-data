#include<iostream>
#include<deque>
using namespace std;

#define ll long long
const int maxn=2e6+10,inf=1e9;
int n,mn[maxn],mncnt[maxn],qcnt[maxn]; ll d,xi[maxn],ans;
struct node{ ll ed; int len,cnt; };

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc,T; cin>>tc>>T;
    if(tc==11||tc==2){
        while(T--){
            cin>>n>>d; ans=0;
            for(int i=1;i<=n;i++)cin>>xi[i];
            d/=(xi[2]-xi[1]);
            if(d==0||d==1){
                cout<<0<<endl;
                continue;
            }
            for(int i=1;i<=n;i++)if((i+d*2-1)<=n)ans++;
            cout<<ans<<endl;
        }
        return 0;
    }
    while(T--){
        cin>>n>>d; ans=0;
        for(int i=1;i<=n;i++)cin>>xi[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)mn[j]=inf,mncnt[j]=0;
            deque<node> q;
            for(int j=i;j<=n;j++){
                while(q.size()&&xi[j]>q.front().ed)qcnt[q.front().len]-=q.front().cnt,q.pop_front();
                if(!q.size()&&i!=j)break;
                if(i!=j)mncnt[j]=min(qcnt[q.front().len],3),mn[j]=q.front().len;
                else mncnt[j]=1,mn[j]=0;
                while(q.size()&&q.back().len>mn[j]+1)qcnt[q.back().len]-=q.back().cnt,q.pop_back();
                qcnt[mn[j]+1]+=mncnt[j]; q.push_back({xi[j]+d,mn[j]+1,mncnt[j]});
                if(mncnt[j]==2)ans++;
            }
            for(auto x:q)qcnt[x.len]-=x.cnt;
        }
        cout<<ans<<endl;
    }
}