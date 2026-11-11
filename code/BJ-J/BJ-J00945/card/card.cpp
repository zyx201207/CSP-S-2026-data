#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],b[1001000];
queue<int> q;
bool bol[10000100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        for(int i=j;i<n;i++){


            if(bol[a[i]]){
                while(q.front()!=a[i]){
                    q.pop();
                }
                q.pop();
            }
            q.push(a[i]);
            bol[a[i]]=1;
            while(!q.empty()){
                b[q.front()]++;
                q.pop();
            }

        }

    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }

}
