#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;

int n,m;
int a[N],ans[N];
int dat[N];
void work(int p){
    stack<int> q;
    for(int i=p;i<=n;i++){
        if(dat[a[i]]==0){
            dat[a[i]]++;
            q.push(a[i]);
        }
        else {
            while(!q.empty()){
                int v=q.top();
                if(v==a[i]){
                    break;
                }else{
                    dat[v]--;
                    q.pop();
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        ans[i]+=dat[i];
        dat[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        dat[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        work(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
