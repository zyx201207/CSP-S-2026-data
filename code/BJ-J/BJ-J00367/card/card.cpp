#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],ans[300005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                s.push(a[j]);
                f[a[j]]=1;
            }
            else if(f[a[j]]==1){
                while(s.top()!=a[j]){
                    f[s.top()]=0;
                    //cout<<s.top()<<' ';
                    s.pop();
                }
            }

        }
        while(!s.empty()){
            ans[s.top()]++;
            //cout<<s.top()<<' ';
            f[s.top()]=0;
            s.pop();
        }
        //memset(f,0,sizeof(f));
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
