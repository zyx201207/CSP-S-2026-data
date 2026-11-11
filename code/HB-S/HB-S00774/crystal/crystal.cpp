#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,r,b=0,c=0,an1;
cin>>n>>m;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
        b=0;
        r=a[i];
    for(int j=0;j<n;j++){
        if(r=a[j]){
            b=b+1;
        }
    }
    if(b!=c){
        c=max(b,c);
        an1=r;
    }
}

return 0;
}
