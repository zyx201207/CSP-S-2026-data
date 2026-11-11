#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

bool f[500005];
int n,m,a[500005],kind[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        queue<int>q;
        for(int j=i;j<=n;j++){
            if(!f[a[j]]){
                q.push(a[j]);
                f[a[j]]=1;
            }
            else{
                while(!q.empty()&&f[a[j]]){
                    f[q.back()]=0;
                    q.pop();
                }
                q.push(a[j]);
                f[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(f[j]==1){
                    kind[j]++;
                    f[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<kind[i]<<" ";
    }
    return 0;
}
