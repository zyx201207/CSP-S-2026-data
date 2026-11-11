#include<iostream>
#include<stack>
#include<cstring>//please give me 48 pts!!!
using namespace std;
int n,m,a[500005],ans[500005],v[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){//#1-12
        stack<int> s;
        for(int i=0;i<=m;i++){
            v[i]=0;
        }
        for(int j=i;j<=n;j++){
            if(v[a[j]]==1){
                while(1){
                    int t=s.top();
                    if(t==a[j]) break;
                    s.pop();
                    v[t]=0;
                }
            }
            else{
                s.push(a[j]);
                v[a[j]]=1;
            }
        }
        while(!s.empty()){
            int t=s.top();
            ans[t]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
/*
fwtbzdzd
bywqscfm
xlybgsls
kbqdh
dwhxzxsm
qshyshd
qnddw
qnddw
lkwdqzb
dpxcdcj
wxytzjn
sbzjwzj
zywnnkwzydxz
bkzyzmykxdw
wmzwbfmygl
zstyyjwmzs
zzgsjnmhmm
dbzbxddzss
zswhzwnegz
zhaemcdfwtb
*/
