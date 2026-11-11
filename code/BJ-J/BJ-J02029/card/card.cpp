#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
bool v[2*N];
int ans[2*N];
stack<int>s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","s",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        for(int j=i;j<=n;j++){
            if(v[a[j]]){
                while(s.top()!=a[j]){
                    v[s.top()]=0;
                    ans[s.top()]--;
                    s.pop();
                }
            }else{
                s.push(a[j]);
                v[a[j]]=1;
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
