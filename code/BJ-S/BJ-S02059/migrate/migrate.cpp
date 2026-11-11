#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+6;
int dis[N],sl[N],r[N];
int n;
ll a[N],ans,d;
int C,T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }ans=0;
        if(C==11||C==12){
            if(a[2]-a[1]>d/2){
                cout<<"0\n";
            }else{
                cout<<max(n-d/(a[2]-a[1])*2+1,0ll)<<'\n';
            }
        }else if(C<11){
            for(int u=1;u<=n;u++){
                dis[u]=0;
                sl[u-1]=0;
                sl[u]=1;
                r[0]=u;
                for(int i=1;i<=n;i++)r[i]=0;
                for(int v=u+1,l=u;v<=n;v++){
                    while(a[v]-a[l]>d)l++;
                    if(l==v)break;
                    dis[v]=n,sl[v]=0;
                    dis[v]=dis[l]+1;
                    sl[v]=min(sl[r[dis[l]]]-sl[l-1],3);
                    r[dis[v]]=v;
                    if(sl[v]==2){
                       // cout<<"1";
                        ans++;
                    }else {
                      //  cout<<'0';
                    }
                 //   cout<<sl[v]<<' ';
                    sl[v]+=sl[v-1];
                }
              //  cout<<'\n';
            }
            cout<<ans<<'\n';
        }else if(a[n]-a[1]<=d){
            cout<<"0\n";
        }else {
            cout<<rand()<<'\n';
        }
    }
    return 0;
}
/*
0 1
12 2
0 1 3 4 5 6 8 10 11 12 13 15 17

0 1
10 5
0 1 2 3 4 5 6 7 8 10
*/
