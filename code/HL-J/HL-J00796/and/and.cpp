#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],max1=-1e9,ans;

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1; i<=n; i++){
	cin>>a[i];
}
if(m==1){
	cout<<0;
	return 0;
}
if(m==n){
	ans=a[1];
	for(int i=2; i<=n; i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
if(m==2){
	for(int i=1; i<=n; i++){
	for(int j=i+1; j<=n; j++){
		max1=max(max1,a[i]&a[j]);
	}
}
cout<<max1;
return 0;
}
return 0;
}
/*
5 3
31 3 1 15 7
*/