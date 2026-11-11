#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+10,M=3*1e5+10;
int n,m;
int a[N],bk[M],res[M];
stack <int> s;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(bk,0,sizeof(bk));
        for(int j=i;j<=n;j++){
            if(!bk[a[j]]){
                s.push(a[j]);
                bk[a[j]]=1;
            }
            else{
                while(s.top()!=a[j]){
                    bk[s.top()]=0;
                    s.pop();
                }
                s.pop();
                s.push(a[j]);
                bk[a[j]]=1;
            }
        }
        while(!s.empty()){
            res[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
