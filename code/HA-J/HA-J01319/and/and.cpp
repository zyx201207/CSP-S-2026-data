#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],jl[2005][2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
if(m==1){
	int max1=0;
for(int i=1;i<=n;i++){
	max1=max(max1,a[i]);
}
cout<<max1;
return 0;
}
int maxs=0;
for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++){
jl[i][j]=a[i]&a[j];
maxs=max(maxs,jl[i][j]);
}
}
	cout<<maxs;
	return 0;
}
