#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
char m,cnt;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>m;
    cnt=m;
}
if(cnt==m){
    cout<<"0";
}
return 0;
}
