#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],p,sum[300005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            p=1;
        }
    }
    if(!p){
        for(int i=1;i<=n;i++){
            f[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<f[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                s.push(a[j]);
                f[a[j]]=1;
            }else{
                while(!s.empty()){
                    if(s.top()==a[j]){
                        break;
                    }
                    f[s.top()]=0;
                    s.pop();
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(f[i]==1){
                sum[i]++;
            }
        }
        while(!s.empty()){
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
