#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char b;
};
node c[500010];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,i,j;
cin>>n;
long long he=0;
for(i=0;i<n;i++){
    cin>>c[i].a>>c[i].b;
}
if(n==1){
   cout<<0;
    return 0;
}else if(n==2&&c[0].b!=c[1].b){
    cout<<min(c[0].a,c[1].a);
    return 0;
}else if(n==2&&c[0].b==c[1].b){
    cout<<0;
    return 0;
}
for(i=0;i<n;i++){
    if(c[i].b!=c[n-i-1].b){
        he+=c[i].a;
    }
}
cout<<he;
return 0;
}
