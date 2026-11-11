#include<bits/stdc++.h>
using namespace std;
int a[1000000+10];
int main(){
    freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d,num=0;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=0;j<c;j++){
        cin>>a[j];
        }
    }
for(int j=0;j<t;j++){
    a[j]=a[j+1]+a[j];
}
d=n-2;
for(int j=0;j<n;j++){
    if(a[j]==a[j+1] and a[j+1]!=1){
        num--;
    }
    cout<<n-num<<endl;
}

return 0;
}
