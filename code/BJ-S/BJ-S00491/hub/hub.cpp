#include<bits/stdc++.h>
using namespace std;
const N=1e5*5+8;
bool p[N];
int u[N],v[N],a[N];
int main(){
    freopen("hub.in",r,stdin);
    freopen("hub.out",w,stdout);
    int c,t,sum=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int minn=9999999,p=0;
        for(int j=1;j<=N;j++){
            a[j]=0;
        }
        cin>>n>>k;
        for(int j=1;j<=n-1;j++){
            cin>>u[j]>>v[j];
            a[u[j]]++;
            a[v[j]]++;
            if(a[u[j]]<minn){
                minn=a[u[j]];
                p=u[j]
            }
            if(a[v[j]]<minn){
                minn=a[v[j]];
                p=v[j]
            }
        }
        cout<<(p-1)/2;
    }
    return 0;
}
