include<bits/stdc++.h>
using namespace std;
int a[10001000];
int main(){
feropen(".in","r",sdin);
feropen(".out","w",sdin);
ios::sync_with_stdio(false);
cin .tie(0);
int n,m;
cin>>n>>m;
for(int i=2;i<=n;i++){
cin>>a[n];
bool flag=true;
if(i==n-1 ){
cin>>a[i];
}
if(a[n-1]-a[i]!=a[n-1]-a[i]){
        flag=fales;
}
}
return 0;
}
