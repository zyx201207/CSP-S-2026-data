#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int jsq[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];	
b[i]=a[i];
}
int k=1;
for(int x=1;x<=n;x++){
	for(int i=x;i<=n;i++){
	for(int j=x;j<i;j++){
if(a[i]==a[j]){
	for(int z=j;z<i;z++)a[z]=0;
}
	}
}
for(int i=1;i<=n;i++){
if(a[i]!=0)jsq[a[i]]++;
}
for(int i=1;i<=n;i++){
	a[i]=b[i];
}
}
for(int i=1;i<=m;i++){
	cout<<jsq[i]<<' ';
}
return 0;
}
