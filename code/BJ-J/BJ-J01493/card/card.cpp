#include<bits/stdc++.h>
using namespace std;
int n,m,n1,siz;
int a[500010],vis[300010],t[300010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    n1=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int z=1;z<=n;z++){
            siz=1;
        for(int i=1;i<=m;i++)vis[i]=0;
        vector<int>d;
        d.push_back(0);
        for(int i=z;i<=n;i++){
            if(vis[a[i]]!=0){
                for(int j=1;j<=i-vis[a[i]]-1;j++){
                    d.pop_back();
                    siz--;
                }
            }
            else{
                d.push_back(a[i]);
                vis[a[i]]=i;
                siz++;
            }
        }
        for(int i=1;i<=siz;i++){
                t[d[i]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}
