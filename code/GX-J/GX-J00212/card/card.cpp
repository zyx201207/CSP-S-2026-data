#include<bits/stdc++.h>
using namespace std;
int n,m,c,a[500005],p[500005],o[500005];
queue<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(o[a[j]]==1){
                while(q.front()!=a[j]){
                    o[q.front()] = 0;
                    q.pop();
                }
                q.pop();
            }
            q.push(a[j]);
            o[a[j]] = 1;
        }
        for(int j=1;j<=m;j++){
            if(o[j])
                p[j]++;
            o[j] = 0;
        }
        while(!q.empty()){
           o[q.front()] = 0;
                    cout<<q.front()<<" ";
            q.pop();
        }
            cout<<"\n";
    }
    for(int i=1;i<=m;i++)
        cout<<p[i]<<" ";
    return 0;
}
