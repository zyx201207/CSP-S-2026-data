#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],y;
int qw(){
int i=1;
while(a[i+1]==a[1])
i++;
return i;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);	
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=m;i++){
sort(a+1,a+n+1);
a[1]++;	
y=max(y,qw());	
}
cout<<y;	
return 0;
} 

