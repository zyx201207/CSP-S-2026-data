#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=200002,maxm=100002;
int a[maxn],k[maxm],t[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        int w=0;
        for(int j=i;j<=n;j++){
            for(int f=1;f<=w;f++){
                if(t[f]==a[j]){
                    for(int p=f;p<=w;p++)t[p]=0;
                    w=f-1;
                    break;
                }
            }
            t[++w]=a[j];
        }
        for(int i=1;i<=w;i++)k[t[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<k[i]<<" ";
    return 0;
}
