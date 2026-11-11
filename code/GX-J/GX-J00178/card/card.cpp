#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=5e5+10;
long long a[maxn];
int t[maxn],p[maxn];
queue<long long>q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            p[i]=0;
        }
        for(int j=i;j<=n;j++){
            q.push(a[j]);
            p[a[j]]++;
            if(p[a[j]]>1){
                long long x=q.front();
                do{
                    x=q.front();
                    p[x]=0;
                    q.pop();
                }while(x!=a[j]);
                q.push(a[j]);
            }
        }
        while(!q.empty()){
            long long u=q.front();
            t[u]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
