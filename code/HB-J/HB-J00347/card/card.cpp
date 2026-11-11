#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
bool v,f[N];
stack <int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]<a[i-1]) v=1;
    }
    if (!v){
        for (int i=1;i<=m;i++)
            cout<<n<<' ';
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (f[a[j]]){
                while (s.top()!=a[j]){
                    f[s.top()]=0;
                    s.pop();
                }
            }
            else{
                s.push(a[j]);
                f[a[j]]=1;
            }
        }
        while (!s.empty()) s.pop();
        for (int j=1;j<=m;j++){
            if (f[j]) ans[j]++;
        }
        memset(f,0,sizeof f);
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
