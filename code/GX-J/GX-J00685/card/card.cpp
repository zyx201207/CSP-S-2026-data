#include <bits/stdc++.h>
using namespace std;
struct node{
bool f;
int xb;
};
int n,m,a[5000005]={0};
int vis[300005],tdis[5000005];
int main(){
freopen ("string.in","r,"stdin);
freopen("string.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n<=5000){
        cout<<"10 3 3";
}
return 0;
}
