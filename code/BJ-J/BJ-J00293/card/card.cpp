#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int M=3005;
int vis[N],pos[N];
int a[N];
int rond[N];
int st[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        h=1,t=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                if(st[pos[a[j]]] != a[j]|| pos[a[j]]>t){
                    st[++t]=a[j];
                    pos[a[j]]=t;
                }
                else{
                    t=st[pos[a[j]]];
                    pos[a[j]]=t;
                }
            }
            else{
                st[++t]=a[j];
                vis[a[j]]=1;
                pos[a[j]]=t;
            }
        }
        for(int j=1;j<=m;j++){
            vis[j]=0;
            pos[j]=0;
        }
        for(int j=h;j<=t;j++){
            rond[st[j]]++;
            st[j]=0;
        }
    }
    cout<<rond[1];
    for(int i=2;i<=m;i++){
        cout<<" "<<rond[i];
    }
    return 0;
}