#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2,M=3e5+2;
int n,m,a[N],b[M],c[N],e[M],s[N],x,y,sum=0;
void reset(int u){
    for(int i=1;i<=u;i++) c[i]=1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    reset(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        sum+=c[i];
        if(i!=e[a[i]]){
            c[i+1]-=sum;
            c[e[a[i]]]+=sum;
        }
        b[a[i]]=sum;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
