#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int main(){
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);

int n=0,m=0,a[300007]={0},i=0,s=0;
cin>>n>>m;
while(i<n){
i++;
cin>>a[i];
}
sort(a+1,a+n+1,cmp);
if(m==1){
cout<<a[1];
}else{
s=a[1];
i=1;
while(i<m){
i++;
s&=a[i];
}
}
return 0;
}
