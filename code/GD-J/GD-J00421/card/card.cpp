#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[10000001],b[10000001];
bool vis[100000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> d;
        for(int j=0;j<=n;j++) vis[j]=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(d.top()!=a[j]) {
                    d.pop();
                    //cout<<d.top()<<" ";
                }
            }
            //cout<<endl;
            //cout<<a[j]<<" ";
            d.push(a[j]);
            vis[a[j]]=1;
        }
        //cout<<endl;
        while(!d.empty()){
            cout<<d.top()<<" ";
            b[d.top()]++;
            d.pop();
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
    return 0;
}
