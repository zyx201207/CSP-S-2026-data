#include <bits/stdc++.h>

using namespace std;

const int N=5e5+5;
int n,m;
int a[N],cnt[N]={0};
bool b[N]={0};

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int>s;
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            s.push(a[i]);
            if(b[a[i]]==1){
                while(s.top()!=a[i]){
                    s.pop();
                }
            }else{
                b[a[i]]=1;
            }
        }
        while(!s.empty()){
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
}
