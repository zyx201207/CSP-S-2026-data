#include<bits/stdc++.h>
using namespace std;
const int M=3e5+10;
const int N=5e5+10;
vector<int>p[N];
int n,m,a[N],ans[M];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
p[a[i]].push_back(i);
}
for(int i=1;i<=n;i++){
for(int j=i;j<=n;j++){
j=p[a[j]][p[a[j]].size()-1];
ans[a[j]]++;
 }
}
for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
return 0;
}
