#include<bits/stdc++.h>
using namespace std;
long long aa[500010],aaa[500010];
bool vis[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,a[500010],m;
    vector<int>v;
    cin>>n>>m;
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
    }
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=m;j+=1){
            vis[j]=true;
        }
        for(int j=1;j<=m;j+=1){
            aaa[j]=0;
        }
        for(int j=i;j<=n;j+=1){
            if(vis[a[j]]==true&&aaa[a[j]]<=1){
                for(int k=0;k<v.size();k+=1){
                    if(v[k]==a[j]){
                        for(int l=k;l<v.size();l+=1){
                            vis[a[j]]=false;
                            aaa[a[j]]+=1;
                            v[l]=0;
                        }
                        v.push_back(a[j]);
                        break;
                    }
                }
            }
            if(vis[a[j]]==true&&aaa[a[j]]<=1){
                    v.push_back(a[j]);
            }
        }
        for(int d=1;d<=m;d+=1){
            for(int w=0;w<v.size();w+=1){
                if(v[w]==d){
                    aa[d]+=1;
                }
            }
        }
    }
    for(int i=1;i<=m;i+=1){
        cout<<aa[i]<<" ";
    }
}
