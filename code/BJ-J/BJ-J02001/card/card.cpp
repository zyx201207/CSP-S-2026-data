#include<bits/stdc++.h>
using namespace std;
int m,n;
const int N=5e5+1;
const int M=3e5+1;
unsigned long long ans[M];
int p[N];
void solve(int l){
    stack<int> sta;
    int a[M]={};
    for(int i=l;i<=n;i++){
        if(a[p[i]]==0){
            a[p[i]]++;
            sta.push(p[i]);
        }
        else{
            while(!sta.empty()){
                int t=sta.top();
                if(p[i]==t){
                    break;
                }
                else{
                    a[t]--;
                    sta.pop();
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        ans[i]+=a[i];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}