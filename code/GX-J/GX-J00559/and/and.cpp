#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
int mx=0;
for(int i=1;i<=n;i++){
    int k;
    cin>>k;
    if(k>mx){
        mx=k;
    }
    }

cout<<mx;
return 0;
}


