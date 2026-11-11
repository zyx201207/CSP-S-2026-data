#include<bits/stdc++.h>
using namespace std;
long long n,m,num=0,tmp=0,hhj=0;
long long a[100005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
    num+=a[i];
}
num=(num+m)/n;
for(int i=0;i<n;i++){
    if(a[i]==a[i+1])
        hhj++;
}
if(n==hhj+1){
    cout<<n;
}else{
for(int i=1;i<n;i++){
        if(a[i]>=0){
    if(a[i]-num<=m){
        tmp++;
        }
    }else if(a[i]+num<=m){
        tmp++;
        }

}
cout<<tmp;

}

return 0;
}
