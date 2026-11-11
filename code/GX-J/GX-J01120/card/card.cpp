#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[3005];
vector<int>a;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    int s;
    cin>>s;
    a.push_back(s);
}
for(int i=1;i<=m;i++){
    cout<<i<<' ';
}
return 0;
}
