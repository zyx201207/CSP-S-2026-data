#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a;
queue<int> q,q2;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        q.push(a);
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        if(q.size()<m)break;
        n=q.size();
        while(n--){
            a=q.front();
            q.pop();
            if((a&(1<<i)))q.push(a);
            else q2.push(a);
        }
        if(q.size()>=m){
            ans+=(1<<i);
            while(!q2.empty())q2.pop();
        }else{
            while(!q2.empty()){
                q.push(q2.front());
                q2.pop();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}