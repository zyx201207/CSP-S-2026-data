#include<bits/stdc++.h>
using namespace std;
const int M=100001;
long long n,m;
long long a[M],b[M],c[M],d[M],p[M],t[M],vis[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[n-i+1]=a[i];
    }
    for(int i=1;i<=n;i++){
        if(vis[b[i]]==0){
            vis[b[i]]=1;
            c[i]++;
            p[b[i]]=i;
        }else {
            c[i]=n;
            c[i]--;
            c[p[b[i]]]++;
        }
    }
    for(int i=n;i>=1;i--){
        //d[i]=d[i+1]+c[i];
        d[i]=c[i];
    }
    for(int i=1;i<=n;i++){
        t[a[i]]+=d[i];
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
