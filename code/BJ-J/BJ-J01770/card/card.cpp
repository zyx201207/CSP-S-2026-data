#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5;
int m,n;
int a[N],ans[N];
bool z[N];
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        z[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        q.push(a[i]);
        int v[N]={};
        v[a[i]]=1;
        int k=i+1;
        while(k<=n){
            int f=q.front();
            if(v[a[k]]==1){
                while(f!=a[k]){
                    v[f]=0;
                    q.pop();
                }
                q.pop();
                while(f!=a[k]){
                    v[f]=0;
                    q.pop();
                }
            }
            q.push(a[k]);
            v[a[k]]=1;
            k++;
        }
        while(k>=i+1){
            int f=q.front();
            ans[f]++;
            q.pop();
            k--;
        }
    }
    for(int i=1;i<=m;i++){
        if(z[i]) cout<<ans[i]<<" ";
    }
    return 0;
}
