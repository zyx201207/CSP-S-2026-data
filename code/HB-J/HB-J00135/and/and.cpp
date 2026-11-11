#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){

return a>b;
}


int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);

int m,n,ans=0;
int f[1005]=0;
int a[INT_MAX];
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];

}
sort(a,a+n,cmp);
while(f[m-1]=1){
for(int i=1;i<=m;i++){
   ans=a[i]&a[i+1];
   f[i]=1;
   f[i+1]=1;
if(f[i]==1){
   continue;

}


}



}
cout<<ans;
