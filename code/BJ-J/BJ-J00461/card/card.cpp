#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],flag[500005],ans[500005];
stack<int>s;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        for(int j=i;j<=n;j++){
            if(flag[a[j]]==1){
                while(s.top()!=a[j]){
                    flag[s.top()]--;
                    s.pop();
                }
            }
            else{
                s.push(a[j]);
                flag[a[j]]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(flag[i]==1)ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
