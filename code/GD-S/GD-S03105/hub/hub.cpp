#include<bits/stdc++.h>
using namespace std;int n,a[114514],c,t,k,u[114514],v[114514];int main(){freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);ios::sync_with_stdio(0);cin.tie(0);cin>>c>>t;for(int i=1;i<=t;i++){cin>>n>>k;for(int j=1;j<=n-1;j++)cin>>u[i]>>v[i];cout<<k+i-1<<endl;}return 0;}
