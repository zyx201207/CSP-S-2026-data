#include<bits/stdc++.h>
using namespace std;
int cnt=0,ans=0;
bool fly(int a,int b,int d){
if(a+d>=b)return true;
else return false;}
int main(){
    int c,t,n[200005],d[200005],x[200005];//d体力，n
    cin >> c >> t ;
    for(int i=1;i<t;i++){cin >> n[i] >> d[i] ;
    for(int j=1;j<=n[i];j++){cin >> x[i];
    for(int k=1;k<=x[n[i]]%d+1;k++){
    if(fly(x[k],x[k+1])cnt++;
}
    }if(cnt==2){ans++;cnt=0;}}
cout << ans;
return 0;}