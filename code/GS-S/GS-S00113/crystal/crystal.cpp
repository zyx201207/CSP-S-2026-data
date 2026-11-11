#include<bits/stdc++.h>
using namespace std;
int a[5000010],b[5000010];
 int main (){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);  
    int m,n,mout=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	   cin>>a[i];
	   if(i==1)b[i]=a[i];
   }
    sort(a+1,a+n+1);
    int x,max,begin=1,end;
        max=0;
    for(i=2;i<=n;i++){
        mid=a[i];
        x=0;
        max=0;
        cout<<a-b;
}
return 0;
