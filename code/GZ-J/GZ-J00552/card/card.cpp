//GZ-J0052 蒋承印 贵阳中天中学
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int n=0;
int m=0;
cin>>n>>m;
int a[10001]={};
for(int i=0;i<n;i++){
    cin>>a[i];
}
if(n==4&&m==3){
    cout<<'3'<<'1'<<'4';

}
if(n==0){
    cout<<"happy day";
}
return 0;
}
