#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
stack <int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[N]={};
        for(int j=i;j<=n;j++){
            if(b[a[j]]==1){
                while(q.top()!=a[j]){
                    b[q.top()]--;
                    q.pop();
                }
                b[a[j]]=1;
            }else{
                q.push(a[j]);
                b[a[j]]=1;
            }
        }
        while(!q.empty()){
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
