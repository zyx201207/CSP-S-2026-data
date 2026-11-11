#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005];
int a[500005];
int f[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<int>s;
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(f[a[j]]!=0){
                while(s.top()!=a[j]){
                    f[s.top()]--;
                    s.pop();
                }
            }else{
                s.push(a[j]);
                f[a[j]]++;
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
