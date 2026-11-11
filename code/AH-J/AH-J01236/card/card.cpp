#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int f[300005];
int t[300005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int tmp;
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(f[a[j]]==1){
                while(1){
                    tmp=s.top();
                    s.pop();
                    f[tmp]=0;
                    if(tmp==a[j]){
                        break;
                    }
                }
            }
            s.push(a[j]);
            f[a[j]]=1;
        }
        while(!s.empty()){
            tmp=s.top();
            s.pop();
            t[tmp]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
