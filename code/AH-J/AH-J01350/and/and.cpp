#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,q,num=0;
cin>>n>>m;
int a[n];
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=1;i<=n;i++){
for(int j=i;j<=n;j++){
if(a[j]<a[j+1]){
q=a[j+1];
a[j+1]=a[j];
a[j]=q;
}
}
}
num=a[1];
for(int i=1;i<=m;i++){
num&=a[i+1];
}
cout<<num;
fclose(stdin);
fclose(stdout);
return 0;
}
