#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N],n,m;
int stk[N],in[N],ans[N],top=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++){
        memset(in,0,sizeof(in));
        for (int j=i;j<=n;j++){
            if (in[a[j]]){
                while (stk[top]!=a[j])in[stk[top--]]=0;
            }
            else{
                stk[++top]=a[j];
                in[a[j]]=1;
            }
        }
        while (top)ans[stk[top--]]++;
    }
    for (int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
