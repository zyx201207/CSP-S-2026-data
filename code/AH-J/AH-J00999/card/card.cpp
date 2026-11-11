#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=5e5+5;
int a[dd];
int desk[dd];
stack<int> t;
int total[dd];
int n,m;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++)desk[k]=0;
        for(int j=i;j<=n;j++){
            if(desk[a[j]]==0){
                t.push(a[j]);
                desk[a[j]]++;
            }else{
                for(int i=t.size();i>=1;i--){
                    if(t.top()!=a[j]){
                        desk[t.top()]--;
                        t.pop();
                    }else{
                        desk[t.top()]--;
                        t.pop();
                        break;
                    }
                }
                t.push(a[j]);
                desk[a[j]]++;
            }
        }
        while(!t.empty()){
            total[t.top()]++;
            t.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<total[i]<<' ';
}
