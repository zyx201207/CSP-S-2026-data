#include<bits/stdc++.h>
using namespace std;
struct num{int cs,s;}a[500005];
int main(){freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
queue<int> q;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i].s;
for(int i=1;i<=n;i++){for(int j=i;i<=n;j++){q.push(a[j]);
if(a[i].s==a[j])for(int k=i;k<=j-1;k++)q.pop();}
for(int i=1;i<=m;i++)if(q==i)a[i].cs++;}
for(int i=1;i<=m;i++)cout<<a[i].cs;
return 0;}
