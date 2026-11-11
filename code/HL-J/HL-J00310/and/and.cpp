#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
int sum[1000000];
int a[1000000];
cin>>n>>m;
for(int i=1;i<=m;i++){
    cin>>a[i-1];
    if(i-1>0){
        if(a[i-1]>=a[i-2]){
            sum[i-2]=a[i-1];
        }
    }
}
int b=sum[0];
for(int j=1;j<m;j++){
    b=b&&sum[j];
}
cout<<b;

return 0;
}
