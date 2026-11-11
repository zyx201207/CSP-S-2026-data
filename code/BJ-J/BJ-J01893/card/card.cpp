#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=513;
int n,m,a[N],b[N],inq[N];
deque<int>dq;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(inq,0,sizeof(inq));
        for(int j=i;j<=n;j++){
            if(!inq[a[i]]){
                    dq.push_back(a[i]);
                inq[a[i]]=1;
            }else {
                while(dq.back()!=a[i]){
                    inq[dq.back()]=0;
                    dq.pop_back();
                }
            }
            
        }
        while(!dq.empty()){
            
            b[dq.front()]++;
            dq.pop_front();
        }
        
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    return 0;
}
