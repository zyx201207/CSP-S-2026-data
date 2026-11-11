#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,z=500005,k,ans=0;
int w[z],x[z],y[z];//w地铁口到站厅，s.t站厅走到站台
struct st{
int a;
int t;
}s[z];
bool cmp(s a,s b){
return s.t<b.t;
}
int main(){
cin >> c >> n >> m >> d >> q;
for(int i=1;i<=m;i++){
cin >> w[i];}
cin >> k;
for(int i=1;i<=k;i++){
cin >> s[i].a >> s[i].t;
}
for(int i=1;i<=q;i++){
cin >> x[i] >> y[i];
ans=ans+w[x[i]]+w[y[i]]+s[x[i]].t+s[y[i]].t;
for(int j=1;j<=k;j++){
sort(s+1,s+n+1,cmp);
if(s[j].a!=y[i])ans+=s[j].t;
}
cout << ans;
}
return 0;
}