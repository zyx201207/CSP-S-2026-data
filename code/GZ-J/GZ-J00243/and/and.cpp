//GZ-J0243 安顺市实验学校 李浩淼
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,nm=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
    nm=a[n];

for(int i=1;i<m;i++){
nm=and(nm,a[n-i]);
cout<<nm<<endl;
}
cout<<nm;
return 0;
}
