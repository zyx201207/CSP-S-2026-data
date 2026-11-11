#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
int a[n],num=-1;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    if(j==i)continue;
    num=max(num,a[i]&a[j]);
    }
}
cout<<num<<endl;
return 0;
}