#include<bits/stdc++.h>
using namespace std;
long long m,n,a[20005],b,ans,ans1[20005],c,d=134217727;
bool p=0;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);

for(int i=1;i<=2*m-1;i++){
    ans=a[n-i];
    while(ans!=1){
        ans/=2;
        ans1[i]++;
    }
}
for(int i=1;i<=2*m-1;i++){
    if(ans1[i]==ans1[i+1]){
        c++;
    }
    if(c>=m){
        p=1;
    }
}
if(p=1){

    for(int i=1;i<=m;i++){
        d=int(d&a[n-i]);
    }
}else{
    for(int i=m;i<=2*m;i++){
        d=int(d&a[n-i]);
    }
}
cout<<d<<endl;
return 0;
}
