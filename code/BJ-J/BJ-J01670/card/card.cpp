#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
int sum[N];
queue<int>q;
queue<int>p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool flag=false;
            q.push(a[j]);
            while(q.size()>0){
                int u=q.front();
                q.pop();
                if(u==a[j])flag=true;
                if(flag==false){
                    p.push(u);
                }
            }
            while(p.size()>0){
                q.push(p.front());
                p.pop();
            }
        }
        while(!q.empty()){
            sum[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    return 0;
}
